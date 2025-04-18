#include "attitude.h"

static float pitch = 0;

void attitude_update(gyro_state_t gyro, float dt)
{
    pitch += gyro.y * dt;
}

float attitude_get_pitch(void)
{
    return pitch;
}