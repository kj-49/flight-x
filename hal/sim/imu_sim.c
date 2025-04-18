#include "imu.h"
#include <math.h>

void imu_init(void) {}

imu_data_t imu_read(void)
{
    static float t = 0;
    t += 0.01f;
    return (imu_data_t){ .x = 0, .y = sinf(t) * 10, .z = 0 };
}