#ifndef CTRL_H
#define CTRL_H

#include "pid.h"
#include "common/structures.h"

typedef struct {
    flight_variables_t user_input;
    flight_variables_t actual_values;
    pid_t roll_pid;
    pid_t pitch_pid;
    pid_t yaw_pid;
} controls_t;

void ctrl_init(void);
controls_t ctrl_get_state(void);

#endif