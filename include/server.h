//
// Created by Igor Alentev on 27.01.2023.
//

#ifndef PENDULUM_PRJ_SERVER_H
#define PENDULUM_PRJ_SERVER_H

struct server_config {
    int active;
    char* url;
} srv_config;

int server_start();

int server_run();

int server_stop();

#endif //PENDULUM_PRJ_SERVER_H
