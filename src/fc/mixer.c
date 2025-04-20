#include "mixer.h"
#include "../../hal/motor.h"

float motor_outputs[MOTOR_COUNT] = {0};

void mixer_init(void) {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motor_outputs[i] = 0;
    }
}

void mixer_mix(float throttle, float roll, float pitch, float yaw) {
    motor_outputs[0] = throttle + pitch - roll + yaw;
    motor_outputs[1] = throttle + pitch + roll - yaw;
    motor_outputs[2] = throttle - pitch + roll + yaw;
    motor_outputs[3] = throttle - pitch - roll - yaw;

    // Clamp to [0.0, 1.0]
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (motor_outputs[i] < 0.0f) motor_outputs[i] = 0.0f;
        if (motor_outputs[i] > 1.0f) motor_outputs[i] = 1.0f;
    }
}

void mixer_write_motors(void) {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motor_set_duty(i, motor_outputs[i]);
    }
}
