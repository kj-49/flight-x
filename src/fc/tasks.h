#ifndef TASKS_H
#define TASKS_H

typedef enum {
    TASK_GYRO,
    TASK_ATTITUDE,
    TASK_MIX,
    TASK_COUNT  // Always keep this last
} task_id_t;

#endif