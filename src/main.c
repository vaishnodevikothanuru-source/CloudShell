#include <stdio.h>
#include <string.h>

#include "cloud.h"
#include "vm.h"
#include "storage.h"
#include "network.h"
#include "monitor.h"

#define MAX_INPUT 100

void show_help(void)
{
    printf("\nCloud Administration Shell Commands\n");
    printf("--------------------------------------\n");
    printf("login                         Login to cloud\n");
    printf("logout                        Logout from cloud\n");
    printf("cloud-status                  Show cloud status\n");
    printf("list-vm                       List virtual machines\n");
    printf("start-vm <name>               Start virtual machine\n");
    printf("stop-vm <name>                Stop virtual machine\n");
    printf("status-vm <name>              Show VM status\n");
    printf("list-storage                  List cloud storage\n");
    printf("create-storage <name>         Create storage\n");
    printf("delete-storage <name>         Delete storage\n");
    printf("list-network                  List networks\n");
    printf("network-status                Show network status\n");
    printf("monitor                       Start monitoring\n");
    printf("help                          Show commands\n");
    printf("exit                          Exit shell\n");
}

int main(void)
{
    char input[MAX_INPUT];
    char command[30];
    char argument[50];

    printf("========================================\n");
    printf("      CLOUD ADMINISTRATION SHELL\n");
    printf("========================================\n");

    printf("Type 'help' to display available commands.\n");

    while (1)
    {
        printf("\ncloud> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%29s %49s", command, argument) < 1)
        {
            continue;
        }

        if (strcmp(command, "login") == 0)
        {
            cloud_login();
        }

        else if (strcmp(command, "logout") == 0)
        {
            cloud_logout();
        }

        else if (strcmp(command, "cloud-status") == 0)
        {
            cloud_status();
        }

        else if (strcmp(command, "list-vm") == 0)
        {
            list_vms();
        }

        else if (strcmp(command, "start-vm") == 0)
        {
            if (sscanf(input, "%*s %49s", argument) == 1)
                start_vm(argument);
            else
                printf("Usage: start-vm <name>\n");
        }

        else if (strcmp(command, "stop-vm") == 0)
        {
            if (sscanf(input, "%*s %49s", argument) == 1)
                stop_vm(argument);
            else
                printf("Usage: stop-vm <name>\n");
        }

        else if (strcmp(command, "status-vm") == 0)
        {
            if (sscanf(input, "%*s %49s", argument) == 1)
                status_vm(argument);
            else
                printf("Usage: status-vm <name>\n");
        }

        else if (strcmp(command, "list-storage") == 0)
        {
            list_storage();
        }

        else if (strcmp(command, "create-storage") == 0)
        {
            if (sscanf(input, "%*s %49s", argument) == 1)
                create_storage(argument);
            else
                printf("Usage: create-storage <name>\n");
        }

        else if (strcmp(command, "delete-storage") == 0)
        {
            if (sscanf(input, "%*s %49s", argument) == 1)
                delete_storage(argument);
            else
                printf("Usage: delete-storage <name>\n");
        }

        else if (strcmp(command, "list-network") == 0)
        {
            list_network();
        }

        else if (strcmp(command, "network-status") == 0)
        {
            network_status();
        }

        else if (strcmp(command, "monitor") == 0)
        {
            start_monitor_thread();
        }

        else if (strcmp(command, "help") == 0)
        {
            show_help();
        }

        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting Cloud Administration Shell...\n");
            break;
        }

        else
        {
            printf("Unknown command: %s\n", command);
            printf("Type 'help' for available commands.\n");
        }
    }

    return 0;
}
