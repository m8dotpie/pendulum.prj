//
// Created by Igor Alentev on 27.01.2023.
//

#ifndef PENDULUM_PRJ_SERVER_H
#define PENDULUM_PRJ_SERVER_H

#include "stdlib.h"
#include "lcm/lcm.h"
#include "request_t.h"
#include "response_t.h"

struct SERVER_CFG{
    int active;
    char* msg_url;
    lcm_t* lcm;
    char* CHANNEL_RCV;
    char* CHANNEL_SEND;
    request_t_subscription_t* sub;
    int VERBOSE;
};

extern struct SERVER_CFG srv_config;

enum {
    REQUEST_T_SRV,
    REQUEST_T_API,
};

enum {
    REQUEST_SRV_SAMPLE1,
    REQUEST_SRV_SAMPLE2,
    REQUEST_SRV_SHUTDOWN,
    REQUEST_SRV_STATUS,
};

enum {
    REQUEST_API_SAMPLE1,
    REQUEST_API_SAMPLE2,
};

enum {
    RESPONSE_T_OK,
    RESPONSE_T_E_SRV,
    RESPONSE_T_E_API,
};

enum {
    RESPONSE_OK_RUNNING,
    RESPONSE_OK_SHUTDOWN,
    RESPONSE_OK_RESTART,
    RESPONSE_OK_STATUS1,
};

enum {
    RESPONSE_SRV_ERROR1,
    RESPONSE_SRV_ERROR2,
};

enum {
    RESPONSE_API_ERROR1,
    RESPONSE_API_ERROR2
};

extern struct SERVER_CFG srv_config;

int server_start();

int server_run();

int server_stop();

int server_send_message(int8_t type, int8_t status, int16_t length, char* msg);


#endif //PENDULUM_PRJ_SERVER_H
