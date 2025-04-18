#include "gyro.h"
#include <stdio.h>
#include "util/debug.h"
#include "../../hal/timing.h"

static gyro_state_t gyro_state = {0, 0, 0};
static uint16_t last_update = 0;

void gyro_init(void) {};

void gyro_update(void)
{
    uint64_t now = timing_micros();
    imu_data_t imu_data = imu_read();

    gyro_state.x = imu_data.x;
    gyro_state.y = imu_data.y;
    gyro_state.z = imu_data.z;
    gyro_state.dt = now - last_update;

    last_update = now;
    d_printf("Gyro data: x=%f, y=%f, z=%f\n", gyro_state.x, gyro_state.y, gyro_state.z);
}

gyro_state_t gyro_get_state(void)
{
    return gyro_state;
}