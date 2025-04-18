#ifndef ATTITUDE_H
#define ATTITUDE_H

#include "../../hal/imu.h"

void attitude_update(gyro_data_t gyro, float dt);
float attitude_get_pitch(void);

#endif