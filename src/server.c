//
// Created by Igor Alentev on 27.01.2023.
//

#include "server.h"
#include "memory.h"
#include "stdlib.h"

int server_start() {
    srv_config.active = 1;
    srv_config.url = malloc(sizeof(char) * 27);
    srv_config.url = "udpm://224.0.0.0:7667?ttl=1";
    // start lcm, etc
}

int server_run() {
    while (srv_config.active) {
        // read lcm packets
        // execute commands queue
    }
}

int server_stop() {
    srv_config.active = 0;
    // interrupt hardware, etc
}