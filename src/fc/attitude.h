#ifndef ATTITUDE_H
#define ATTITUDE_H

#include "gyro.h"
#include "common/structures.h"

typedef struct {
    flight_variables_t attitude;
} attitude_state_t;

void attitude_init(void);
void attitude_update(void);
attitude_state_t attitude_get_state(void);

#endif