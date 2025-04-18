#ifndef ATTITUDE_H
#define ATTITUDE_H

#include "gyro.h"

void attitude_update(gyro_state_t gyro, float dt);
float attitude_get_pitch(void);

#endif