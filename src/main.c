#include <stdio.h>
#include "scheduler/scheduler.h"
#include "fc/tasks.h"
#include <stdbool.h>
#include "util/debug.h"

void init(void);

int main(void)
{
    d_printf("Starting \n");
    init();

    scheduler_run();
}

void init(void)
{
    scheduler_init();
}