#ifndef MIXER_H
#define MIXER_H

#include "motor.h"

/**
 * Assuming the following quad configuration:
      Front
       ^
    M1   M2
      \ /
      / \
    M4   M3
       v
      Rear
 * 
 */

typedef struct {
  float motor_outputs[MOTOR_COUNT];
} mixer_state_t;

void mixer_init(void);
void mixer_update(void);
void mixer_mix(float throttle, float roll, float pitch, float yaw);
void mixer_write_motors(void);

#endif