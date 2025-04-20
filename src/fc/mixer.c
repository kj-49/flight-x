#include "mixer.h"
#include "../../hal/motor.h"
#include "ctrl.h"
#include "pid.h"
#include "util/debug.h"

static mixer_state_t mixer_state;

void mixer_init(void) {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        mixer_state.motor_outputs[i] = 0;
    }
}

void mixer_update(void)
{
    controls_t controls = ctrl_get_state();

    float throttle = controls.user_input.throttle;
    float roll = pid_update(&controls.roll_pid, controls.user_input.roll, controls.actual_values.roll);
    float pitch = pid_update(&controls.pitch_pid, controls.user_input.pitch, controls.actual_values.pitch);
    float yaw = pid_update(&controls.yaw_pid, controls.user_input.yaw, controls.actual_values.yaw);

    mixer_mix(throttle, roll, pitch, yaw);
}

void mixer_mix(float throttle, float roll, float pitch, float yaw) {
    mixer_state.motor_outputs[0] = throttle + pitch - roll + yaw;
    mixer_state.motor_outputs[1] = throttle + pitch + roll - yaw;
    mixer_state.motor_outputs[2] = throttle - pitch + roll + yaw;
    mixer_state.motor_outputs[3] = throttle - pitch - roll - yaw;

    // Clamp to [0.0, 1.0]
    for (int i = 0; i < MOTOR_COUNT; i++) {
        if (mixer_state.motor_outputs[i] < 0.0f) mixer_state.motor_outputs[i] = 0.0f;
        if (mixer_state.motor_outputs[i] > 1.0f) mixer_state.motor_outputs[i] = 1.0f;
    }

    d_printf("Mixing: 1=%f, 2=%f, 3=%f, 4=%f\n", mixer_state.motor_outputs[0], mixer_state.motor_outputs[1], mixer_state.motor_outputs[2], mixer_state.motor_outputs[3]);
}

void mixer_write_motors(void) {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motor_set_duty(i, mixer_state.motor_outputs[i]);
    }
}
