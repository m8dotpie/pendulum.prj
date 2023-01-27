//
// Created by Igor Alentev on 27.01.2023.
//

#ifndef PENDULUM_PRJ_SERVER_H
#define PENDULUM_PRJ_SERVER_H

#include "stdlib.h"
#include "lcm/lcm.h"

struct {
    int active;
    char* api_url;
    char* srv_url;
    lcm_t* api_lcm;
    lcm_t* srv_lcm;
} srv_config;

int server_start();

int server_run();

int server_stop();

int server_send_message(int command, int length, char* msg);

int server_send_hardware();

#endif //PENDULUM_PRJ_SERVER_H
