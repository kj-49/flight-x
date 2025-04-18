#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*task_fn)(float dt);

typedef struct {
    task_fn fn;
    uint32_t interval_us;   // how often to run, in microseconds
    uint64_t last_run_us;
} scheduled_task_t;

void scheduler_init(void);
void scheduler_add_task(task_fn fn, uint32_t interval_us);
void scheduler_run(void);

#endif
