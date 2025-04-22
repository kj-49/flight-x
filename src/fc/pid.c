#include "pid.h"

void pid_init(pid_t* pid, float kp, float ki, float kd, float dt) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->dt = dt;
    pid->integral = 0.0f;
    pid->previous_error = 0.0f;
    pid->output_limit = 1000.0f;
    pid->integral_limit = 500.0f;
}

float pid_update(pid_t* pid, float setpoint, float measurement) {
    float error = setpoint - measurement;

    pid->integral += error * pid->dt;

    // Clamp integral to prevent wind-up
    if (pid->integral > pid->integral_limit) pid->integral = pid->integral_limit;
    if (pid->integral < -pid->integral_limit) pid->integral = -pid->integral_limit;

    float derivative = (error - pid->previous_error) / pid->dt;

    float output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;

    // Clamp output
    if (output > pid->output_limit) output = pid->output_limit;
    if (output < -pid->output_limit) output = -pid->output_limit;

    pid->previous_error = error;

    return output;
}

pid_t pid_get_default()
{
    pid_t new;
    pid_init(&new, 1, 1, 1, 1);

    return new;
}
