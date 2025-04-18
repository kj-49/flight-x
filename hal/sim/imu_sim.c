#include "imu.h"
#include <math.h>

void imu_init(void) {}

gyro_data_t imu_read_gyro(void)
{
    static float t = 0;
    t += 0.01f;
    return (gyro_data_t){ .x = 0, .y = sinf(t) * 10, .z = 0 };
}