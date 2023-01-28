//
// Created by Igor Alentev on 27.01.2023.
//

#include "server.h"

struct SERVER_CFG srv_config = {};

static
void handle_api_command(const lcm_recv_buf_t *rbuf, const char *channel,
                        const api_command_t *msg, void *user) {
    if (srv_config.VERBOSE) {
        printf("API event happened\n");
    }
}

static
void handle_server_command(const lcm_recv_buf_t *rbuf, const char *channel,
                           const server_command_t *msg, void *user) {
    if (srv_config.VERBOSE) {
        printf("Server event happened\n");
    }
}


int server_send_message(int cmd, int length, char* msg) {
    server_status_t status;
    status.code = cmd;
    status.length = length;
    status.msg = malloc(sizeof(char) * length);
    strcpy(status.msg, msg);

    server_status_t_publish(srv_config.api_lcm, srv_config.SRV_CHANNEL, &status);
    return 0;
}

int server_send_hardware() {
    return 0;
}

int server_start() {
    srv_config.active = 1; // server is active now

    srv_config.API_CHANNEL = malloc(sizeof(char) * 3);
    srv_config.API_CHANNEL = "API";
    srv_config.SRV_CHANNEL = malloc(sizeof(char) * 6);
    srv_config.SRV_CHANNEL = "SERVER";
    srv_config.VERBOSE = 1; // Logging level

    // channel for communication
    srv_config.msg_url = malloc(sizeof(char) * 27);
    srv_config.msg_url = "udpm://224.0.0.0:7667?ttl=1";

    // start api_lcm, etc
    srv_config.api_lcm = lcm_create(srv_config.msg_url);
    srv_config.srv_lcm = lcm_create(srv_config.msg_url);

    // Input channels initialization
    srv_config.api_sub = api_command_t_subscribe(
            srv_config.api_lcm,
            srv_config.API_CHANNEL,
            &handle_api_command,
            NULL
    );
    srv_config.srv_sub = server_command_t_subscribe(
            srv_config.srv_lcm,
            srv_config.SRV_CHANNEL,
            &handle_server_command,
            NULL
    );

    server_send_message(SERVER_START, 7, "SUCCESS");

    return 0;
}

int read_packet(lcm_t* input_lcm) {
    // TODO: separate thread is better
    int lcm_fd = lcm_get_fileno(input_lcm);
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(lcm_fd, &fds);

    // wait a limited amount of time for an incoming message
    struct timeval timeout = {
            0,  // seconds
            100   // microseconds
    };
    int status = select(lcm_fd + 1, &fds, 0, 0, &timeout);

    if (0 == status) {
        // no messages came
    } else if (FD_ISSET(lcm_fd, &fds)) {
        // LCM has events ready to be processed.
        lcm_handle(input_lcm);
    }
    return 0;
}

int monitor_packets () {
    read_packet(srv_config.api_lcm);
    read_packet(srv_config.srv_lcm);

    return 0;
}

int server_run() {
    while (srv_config.active) {
        monitor_packets();
    }
}

int server_stop() {

    // interrupt hardware, etc
    // IT IS IMPORTANT TO INTERRUPT
    // HARDWARE BEFORE SHUTTING DOWN
    // THE SERVER

    // shutdown server
    srv_config.active = 0;
    server_send_message(SERVER_STOP, 7, "SUCCESS");

    // unsubscribe from both servers
    api_command_t_unsubscribe(srv_config.api_lcm, srv_config.api_sub);
    server_command_t_unsubscribe(srv_config.api_lcm, srv_config.srv_sub);

    // shutdown both lcms
    lcm_destroy(srv_config.api_lcm);
    lcm_destroy(srv_config.srv_lcm);

    return 0;
}