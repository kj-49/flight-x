#include <stdio.h>
#include "scheduler/scheduler.h"
#include "fc/tasks.h"

void task_gyro(void) {
    printf("GYRO task running\n");
}

void task_loop(void) {
    printf("MAIN LOOP running\n");
}

int main(void) {
    scheduler_init();
    scheduler_run();
    return 0;
}
