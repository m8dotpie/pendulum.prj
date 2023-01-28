//
// Created by Igor Alentev on 27.01.2023.
//

#include "server.h"

struct SERVER_CFG srv_config = {};

int server_send_message(int cmd, int length, char* msg) {
    server_status_t status;
    status.code = cmd;
    status.length = length;
    status.msg = malloc(sizeof(char) * length);
    strcpy(status.msg, msg);

    server_status_t_publish(config.lcm, config.SRV_CHANNEL, &status);
    return 0;
}

int server_send_hardware() {
    return 0;
}

int server_start() {
    srv_config.active = 1; // server is active now

    config.API_CHANNEL = malloc(sizeof(char) * 3);
    config.API_CHANNEL = "API";
    config.SRV_CHANNEL = malloc(sizeof(char) * 6);
    config.SRV_CHANNEL = "SERVER";

    // channel for communication
    config.api_url = malloc(sizeof(char) * 27);
    config.api_url = "udpm://224.0.0.0:7667?ttl=1";

    // start lcm, etc
    config.lcm = lcm_create(config.api_url);

    server_send_message(SERVER_START, 7, "SUCCESS");

    return 0;
}

static
void handle_api_command(const lcm_recv_buf_t *rbuf, const char *channel,
                        const api_command_t *msg, void *user) {
    printf("API event happened\n");
}

static
void handle_server_command(const lcm_recv_buf_t *rbuf, const char *channel,
                           const server_command_t *msg, void *user) {
    printf("Server event happened\n");
}

int read_packet() {
    lcm_handle(config.lcm);

    return 0;
}

int monitor_packets () {
    api_command_t_subscription_t *api_sub = api_command_t_subscribe(
            config.lcm,
            config.API_CHANNEL,
            &handle_api_command,
            NULL
    );
    server_command_t_subscription_t *srv_sub = server_command_t_subscribe(
            config.lcm,
            config.SRV_CHANNEL,
            &handle_server_command,
            NULL
    );

    if (read_packet())
        return 1;

    api_command_t_unsubscribe(config.lcm, api_sub);
    server_command_t_unsubscribe(config.lcm, srv_sub);

    return 0;
}

int server_run() {
    while (config.active) {
        monitor_packets();
    }
}

int server_stop() {
    config.active = 0;
    server_send_message(SERVER_STOP, 7, "SUCCESS");
    lcm_destroy(config.lcm);
    // interrupt hardware, etc

    return 0;
}