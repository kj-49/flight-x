#include "ctrl.h"

static controls_t control_state;

void ctrl_init(void)
{
    control_state.pitch_pid = pid_get_default();
    control_state.roll_pid = pid_get_default();
    control_state.yaw_pid = pid_get_default();
}

controls_t ctrl_get_state(void)
{
    return control_state;
}