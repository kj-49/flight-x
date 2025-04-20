#ifndef GYRO_H
#define GYRO_H

#include "imu.h"
#include <stdint.h>

typedef struct {
    float roll_dps, pitch_dps, yaw_dps;
} angular_rate_t;

typedef struct {
    angular_rate_t angular_rate;
    uint16_t dt;
} gyro_state_t;

void gyro_init(void);
void gyro_update(void);
gyro_state_t gyro_get_state(void);

#endif

