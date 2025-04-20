#include "pid.h"

static pid_state_t pid_state = {0, 0, 0, 0, 0};

float pid_update(float error, float dt) {
    pid_state.integral += error * dt;
    float derivative = (error - pid_state.last_error) / dt;
    pid_state.last_error = error;

    pid_state.output = pid_state.kp * error + pid_state.ki * pid_state.integral + pid_state.kd * derivative;
}

pid_state_t pid_get_state(void) {
    return pid_state;
}
