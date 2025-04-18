#ifndef GYRO_H
#define GYRO_H

#include "imu.h"

typedef struct {
    float x, y, z;
} gyro_state_t;

void gyro_init(void);
void gyro_update(void);

#endif

