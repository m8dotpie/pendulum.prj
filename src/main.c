#include <lcm/lcm.h>
#include "exlcm_example_t.h"

int
main(int argc, char ** argv)
{
    lcm_t * lcm = lcm_create(NULL);
    if(!lcm)
        return 1;
    exlcm_example_t my_data = {
            .timestamp = 0,
            .position = { 1, 2, 3 },
            .orientation = { 1, 0, 0, 0 },
    };
    int16_t ranges[15];
    int i;
    for(i = 0; i < 15; i++)
        ranges[i] = i;
    my_data.num_ranges = 15;
    my_data.ranges = ranges;
    my_data.name = "example string";
    my_data.enabled = 1;
    exlcm_example_t_publish(lcm, "EXAMPLE", &my_data);
    lcm_destroy(lcm);
    return 0;
}