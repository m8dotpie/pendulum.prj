//
// Created by Igor Alentev on 27.01.2023.
//

#ifndef PENDULUM_PRJ_SERVER_H
#define PENDULUM_PRJ_SERVER_H

#include "stdlib.h"
#include "lcm/lcm.h"
#include "api_command_t.h"
#include "api_response_t.h"
#include "server_command_t.h"
#include "server_status_t.h"

struct SERVER_CFG {
    int active;
    char* api_url;
    lcm_t* api_lcm;
    char* API_CHANNEL;
    char* SRV_CHANNEL;
};

enum {
    SERVER_START,
    SERVER_ERROR,
    SERVER_REBOOT,
    SERVER_STOP,
};

extern struct SERVER_CFG srv_config;

int server_start();

int server_run();

int server_stop();

int server_send_message(int command, int length, char* msg);

int server_send_hardware();

#endif //PENDULUM_PRJ_SERVER_H
