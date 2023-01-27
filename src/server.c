//
// Created by Igor Alentev on 27.01.2023.
//

#include "server.h"

int server_send_message(int command, int length, char* msg) {
    // init struct and publish it
    return 0;
}

int server_send_hardware() {
    return 0;
}

int server_start() {
    srv_config.active = 1; // server is active now

    // channel for hardware communication
    srv_config.api_url = malloc(sizeof(char) * 27);
    srv_config.api_url = "udpm://224.0.0.0:7667?ttl=1";

    // channel for server communication
    srv_config.srv_url = malloc(sizeof(char) * 27);
    srv_config.srv_url = "udpm://224.0.0.0:7668?ttl=1";

    // start lcm, etc
    srv_config.api_lcm = lcm_create(srv_config.api_url);
    srv_config.srv_lcm = lcm_create(srv_config.srv_url);

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
    lcm_destroy(srv_config.api_lcm);
    lcm_destroy(srv_config.srv_lcm);
    // interrupt hardware, etc

    return 0;
}