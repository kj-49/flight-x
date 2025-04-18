#include "tasks.h"
#include "../../hal/imu.h"
#include <stdio.h>

void task_init()
{
    scheduler_add_task(task_imu, 1000);;
}

void task_imu(float dt)
{
    gyro_data_t g = imu_read_gyro();
    attitude_update(g, dt);

    printf("[IMU] dt: %.4f | gyro: x=%.2f y=%.2f z=%.2f\n", dt, g.x, g.y, g.z);
}
