#include <stdio.h>
#include "scheduler/scheduler.h"
#include "fc/tasks.h"
#include <stdbool.h>

void init(void);

int main(void)
{
    init();

    while(true) {
        scheduler_run();
    }
    return 0;
}

void init(void)
{
    scheduler_init();
}