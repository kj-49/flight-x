#ifndef GYRO_H
#define GYRO_H

#include "imu.h"
#include <stdint.h>

typedef struct {
    float x, y, z;
    uint16_t dt;
} gyro_state_t;

void gyro_init(void);
void gyro_update(void);
gyro_state_t gyro_get_state(void);

#endif

