#include "scheduler.h"
#include "../../hal/timing.h"
#include "gyro.h"
#include <stdio.h>
#include <stdbool.h>
#include "util/debug.h"
#include "attitude.h"

static task_t tasks[TASK_COUNT];
static uint64_t current_micros = 0;

void scheduler_init(void) {
    for (int i = 0; i < TASK_COUNT; i++) {
        tasks[i].task = 0;
        tasks[i].period_us = 0;
        tasks[i].last_run = 0;
    }
    current_micros = 0;

    scheduler_set_task(TASK_GYRO, gyro_update, 1000000);
    scheduler_set_task(TASK_ATTITUDE, attitude_update, 1000000);
}

void scheduler_set_task(task_id_t id, task_func_t task, uint64_t period_us) {
    d_printf("Setting task %d with period %d us\n", id, period_us);
    if (id < TASK_COUNT) {
        tasks[id].task = task;
        tasks[id].period_us = period_us;
        tasks[id].last_run = 0;
    }
}

void scheduler_run(void) {
    d_printf("Running scheduler\n");
    while (true) {
        current_micros = timing_micros();
        for (int i = 0; i < TASK_COUNT; i++) {
            if (tasks[i].task && (current_micros - tasks[i].last_run) >= tasks[i].period_us) {
                tasks[i].last_run = current_micros;
                d_printf("Running task %d\n", i);
                tasks[i].task();
            }
        }
    }
}
