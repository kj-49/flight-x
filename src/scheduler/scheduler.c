#include "scheduler.h"
#include "../../hal/timing.h"

#define MAX_TASKS 10

static scheduled_task_t tasks[MAX_TASKS];
static int num_tasks = 0;

void scheduler_add_task(task_fn fn, uint32_t interval_us)
{
    if (num_tasks >= MAX_TASKS) return;
    tasks[num_tasks++] = (scheduled_task_t){ fn, interval_us, 0 };
}

void scheduler_init(void) {}

void scheduler_run(void)
{
    while (1) {
        uint64_t now = timing_micros();
        for (int i = 0; i < num_tasks; i++) {
            if (now - tasks[i].last_run_us >= tasks[i].interval_us) {
                float dt = (now - tasks[i].last_run_us) / 1000000.0f;
                tasks[i].last_run_us = now;
                tasks[i].fn(dt);
            }
        }
        usleep(100);
    }
}
