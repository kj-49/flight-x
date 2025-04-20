#ifndef PID_H
#define PID_H

typedef struct {
    float kp, ki, kd;
    float integral;
    float last_error;
    float output;
} pid_state_t;

void pid_init(float kp, float ki, float kd);
float pid_update(float error, float dt);
pid_state_t pid_get_state(void);

#endif