//
// Created by dom_iva on 1/27/23.
//

#include <lcm/lcm.h>
#include "exlcm_example_t.h"
#include <stdio.h>
#include "listener.h"

static
void handle_message(const lcm_recv_buf_t *rbuf, const char * channel,
                    const exlcm_example_t * msg, void * user) {
    printf("Received message on channel \"%s\":\n", channel);
    printf("  orientation = (%f, %f, %f, %f)\n",
           msg->orientation[0], msg->orientation[1], msg->orientation[2],
           msg->orientation[3]);
}

int
main(int argc, char ** argv) {
    lcm_t * lcm = lcm_create(NULL);

    if (!lcm)
        return 1;

    exlcm_example_t_subscribe(lcm, "EXAMPLE", &handle_message, NULL);
}