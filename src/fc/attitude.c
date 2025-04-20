#include "attitude.h"
#include "../../hal/timing.h"
#include "util/debug.h"
#include "gyro.h"

static attitude_state_t attitude_state;

void attitude_init(void) {}

void attitude_update(void)
{
    gyro_state_t gyro = gyro_get_state();

    attitude_state.attitude.roll += gyro.angular_rate.roll_dps * gyro.dt;
    attitude_state.attitude.pitch += gyro.angular_rate.pitch_dps * gyro.dt;
    attitude_state.attitude.yaw += gyro.angular_rate.yaw_dps * gyro.dt;

    d_printf("Attitude state: roll=%f, pitch=%f, yaw=%f\n", attitude_state.attitude.roll, attitude_state.attitude.pitch, attitude_state.attitude.yaw);
}

attitude_state_t attitude_get_state(void)
{
    return attitude_state;
}