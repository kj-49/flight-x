#ifndef ATTITUDE_H
#define ATTITUDE_H

#include "gyro.h"

typedef struct {
    float roll;   // Roll angle (X-axis rotation)
    float pitch;  // Pitch angle (Y-axis rotation)
    float yaw;    // Yaw angle (Z-axis rotation)
} attitude_state_t;

void attitude_init(void);
void attitude_update(void);
attitude_state_t attitude_get_state(void);

#endif