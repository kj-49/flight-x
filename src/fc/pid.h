#ifndef PID_H
#define PID_H

typedef struct {
    float kp;
    float ki;
    float kd;

    float integral;
    float previous_error;

    float output_limit;     // max abs(output)
    float integral_limit;   // max abs(integral)

    float dt;               // time step in seconds
} pid_t;
void pid_init(pid_t* pid, float kp, float ki, float kd, float dt);
float pid_update(pid_t* pid, float setpoint, float measurement);

#endif