#include "motor.h"
#include "util/debug.h"

void motor_set_duty(motor_e motor, float duty_cycle)
{
    // Simulate motor duty cycle setting
    d_printf("Motor %d set to duty cycle: %.2f\n", motor, duty_cycle);
}