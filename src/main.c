#include <stdio.h>
#include "scheduler/scheduler.h"
#include "fc/tasks.h"
#include <stdbool.h>
#include "util/debug.h"



void init(void);

int main(void)
{
    printf("Starting \n");
    //fflush(stdout);
     init();

    // scheduler_run();
}

void init(void)
{
    scheduler_init();
}