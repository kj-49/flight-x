#ifndef MOTOR_H
#define MOTOR_H

typedef enum {
    MOTOR_1,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_COUNT
} motor_e;

void motor_set_duty(motor_e motor, float duty_cycle);

#endif