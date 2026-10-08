#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "monitor.h"

void *cloud_monitor(void *arg)
{
    (void)arg;

    while (1)
    {
        sleep(10);

        printf("\n[Cloud Monitor] "
               "Cloud resources are being monitored...\n");

        printf("[Cloud Monitor] "
               "CPU Usage: 42%% | Memory Usage: 58%%\n");

        printf("[Cloud Monitor] "
               "Network: ACTIVE\n");
    }

    return NULL;
}

void start_monitor_thread(void)
{
    pthread_t tid;

    if (pthread_create(&tid, NULL, cloud_monitor, NULL) != 0)
    {
        printf("Failed to start cloud monitoring thread.\n");
        return;
    }

    pthread_detach(tid);

    printf("Cloud monitoring thread started.\n");
}
