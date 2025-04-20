#ifndef MIXER_H
#define MIXER_H

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

void mixer_init(void);
void mixer_mix(float throttle, float roll, float pitch, float yaw);
void mixer_write_motors(void);

#endif