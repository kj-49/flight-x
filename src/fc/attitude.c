#include "attitude.h"
#include "../../hal/timing.h"
#include "util/debug.h"
#include "gyro.h"

static attitude_state_t attitude_state = {0, 0, 0};

void attitude_init(void) {}

void attitude_update()
{
    gyro_state_t gyro = gyro_get_state();

    attitude_state.roll += gyro.x * gyro.dt;
    attitude_state.pitch += gyro.y * gyro.dt;
    attitude_state.yaw += gyro.z * gyro.dt;

    d_printf("Attitude state: roll=%f, pitch=%f, yaw=%f\n", attitude_state.roll, attitude_state.pitch, attitude_state.yaw);
}

attitude_state_t attitude_get_state(void)
{
    return attitude_state;
}