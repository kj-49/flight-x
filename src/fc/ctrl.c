#include "ctrl.h"

static controls_t control_state;

controls_t ctrl_get_state(void)
{
    return control_state;
}