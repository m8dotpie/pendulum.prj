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

    // channel for communication
    srv_config.api_url = malloc(sizeof(char) * 27);
    srv_config.api_url = "udpm://224.0.0.0:7667?ttl=1";

    // start lcm, etc
    srv_config.api_lcm = lcm_create(srv_config.api_url);

    server_send_message(SERVER_START, 7, "SUCCESS");

    return 0;
}

int server_run() {
    while (srv_config.active) {
        // read lcm packets
        // execute commands queue
    }

    return 0;
}

int server_stop() {
    srv_config.active = 0;
    server_send_message(SERVER_STOP, 7, "SUCCESS");
    lcm_destroy(srv_config.api_lcm);
    // interrupt hardware, etc

    return 0;
}