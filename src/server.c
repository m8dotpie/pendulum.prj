#include "server.h"

struct SERVER_CFG srv_config = {};

void handle_api_request(const lcm_recv_buf_t* rbuf, const request_t* msg) {
    if (msg->type != REQUEST_T_API) {
        return;
    }

    printf("Request to API with code: %d\n", msg->code);
}

void handle_srv_request(const lcm_recv_buf_t* rbuf, const request_t* msg) {
    if (msg->type != REQUEST_T_SRV) {
        return;
    }

    printf("Request to SRV with code: %d\n", msg->code);
    if (msg->code == REQUEST_SRV_SHUTDOWN) {
        server_stop();
    }
    else if (msg->code == REQUEST_SRV_STATUS) {
        server_send_message(RESPONSE_T_OK, RESPONSE_OK_RUNNING, 0, NULL);
    }
}

static
void handle_request(const lcm_recv_buf_t *rbuf, const char *channel,
                    const request_t *msg, void *user) {
    if (msg->type == REQUEST_T_API) {
        handle_api_request(rbuf, msg);
    }
    if (msg->type == REQUEST_T_SRV) {
        handle_srv_request(rbuf, msg);
    }
}

int server_send_message(int8_t type, int8_t status, int16_t length, char* msg) {
    if (!msg) {
        msg = malloc(sizeof(char));
        strcpy(msg, "");
    }
    response_t response = {
            .type = type,
            .status = status,
            .length = length,
            .msg = msg,
    };

    response_t_publish(srv_config.lcm, srv_config.CHANNEL_SEND, &response);
    return 0;
}

int server_start() {
    srv_config.active = 1; // server is active now

    srv_config.CHANNEL_RCV = malloc(sizeof(char) * 3);
    srv_config.CHANNEL_RCV = "REQUEST";
    srv_config.CHANNEL_SEND = "RESPONSE";
    srv_config.VERBOSE = 1; // Logging level

    // channel for communication
    srv_config.msg_url = malloc(sizeof(char) * 27);
    srv_config.msg_url = "udpm://224.0.0.0:7667?ttl=1";

    // start lcm, etc
    srv_config.lcm = lcm_create(srv_config.msg_url);

    // Input channels initialization
    srv_config.sub = request_t_subscribe(
            srv_config.lcm,
            srv_config.CHANNEL_RCV,
            &handle_request,
            NULL
    );

    server_send_message(RESPONSE_T_OK, RESPONSE_OK_RUNNING, 0, NULL);

    return 0;
}

int read_packet() {
    // TODO: separate thread is better
    int lcm_fd = lcm_get_fileno(srv_config.lcm);
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(lcm_fd, &fds);

    struct timeval timeout = {
            0,  // seconds
            100   // microseconds
    };

    // wait a limited amount of time for an incoming message
    int status = select(lcm_fd + 1, &fds, 0, 0, &timeout);

    if (0 == status) {
        // no messages came
    } else if (FD_ISSET(lcm_fd, &fds)) {
        // LCM has events ready to be processed.
        lcm_handle(srv_config.lcm);
    }
    return 0;
}

int server_run() {
    while (srv_config.active) {
        read_packet();
    }
}

int server_stop() {
    // interrupt hardware, etc
    // IT IS IMPORTANT TO INTERRUPT
    // HARDWARE BEFORE SHUTTING DOWN
    // THE SERVER

    // shutdown server
    srv_config.active = 0;
    server_send_message(RESPONSE_T_OK, RESPONSE_OK_SHUTDOWN, 0, NULL);

    // unsubscribe from both servers
    request_t_unsubscribe(srv_config.lcm, srv_config.sub);

    // shutdown both lcms
    lcm_destroy(srv_config.lcm);

    return 0;
}