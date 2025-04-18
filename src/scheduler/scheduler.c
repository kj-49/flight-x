#include "scheduler.h"
#include "fc/tasks.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static void (*tasks[])(void) = {
};

#define NUM_TASKS (sizeof(tasks) / sizeof(tasks[0]))

void scheduler_init(void) {
}

void scheduler_run(void) {
    while (1) {
        for (int i = 0; i < NUM_TASKS; i++) {
            tasks[i]();
            usleep(1000);
        }
    }
}
