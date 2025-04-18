#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "tasks.h"
#include <stdint.h>

typedef void (*task_func_t)(void);

typedef struct {
    task_func_t task;
    uint64_t period_us;
    uint64_t last_run;
} task_t;

void scheduler_init(void);
void scheduler_set_task(task_id_t id, task_func_t task, uint64_t period_ms);
void scheduler_run(void);

#endif
