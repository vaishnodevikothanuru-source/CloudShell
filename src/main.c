#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"

int main()
{
    char *line;

    printf("=========================================\n");
    printf("      %s Version %s\n", SHELL_NAME, VERSION);
    printf("=========================================\n");
    printf("Type 'help' to see available commands.\n\n");

    while (1)
    {
        printf("cloud-admin> ");

        line = read_line();

        /* Exit command */
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        /* Help command */
        else if (strcmp(line, "help") == 0)
        {
            printf("\nCloud Administration Commands:\n");
            printf("help          - Show available commands\n");
            printf("list-vm       - List virtual machines\n");
            printf("start-vm      - Start a virtual machine\n");
            printf("stop-vm       - Stop a virtual machine\n");
            printf("server-status - Check server status\n");
            printf("list-storage  - List storage resources\n");
            printf("list-users    - List cloud users\n");
            printf("exit          - Exit the shell\n\n");
        }

        /* List virtual machines */
        else if (strcmp(line, "list-vm") == 0)
        {
            printf("\nVirtual Machines:\n");
            printf("VM-01 : Running\n");
            printf("VM-02 : Stopped\n");
            printf("VM-03 : Running\n\n");
        }

        /* Start virtual machine */
        else if (strcmp(line, "start-vm") == 0)
        {
            printf("Virtual machine started successfully.\n");
        }

        /* Stop virtual machine */
        else if (strcmp(line, "stop-vm") == 0)
        {
            printf("Virtual machine stopped successfully.\n");
        }

        /* Server status */
        else if (strcmp(line, "server-status") == 0)
        {
            printf("Cloud Server Status: ONLINE\n");
        }

        /* List storage */
        else if (strcmp(line, "list-storage") == 0)
        {
            printf("\nStorage Resources:\n");
            printf("Storage-01 : 500 GB\n");
            printf("Storage-02 : 1 TB\n\n");
        }

        /* List users */
        else if (strcmp(line, "list-users") == 0)
        {
            printf("\nCloud Users:\n");
            printf("Admin\n");
            printf("Developer\n");
            printf("Guest\n\n");
        }

        /* Empty command */
        else if (strlen(line) == 0)
        {
            /* Do nothing */
        }

        /* Unknown command */
        else
        {
            printf("Unknown command: %s\n", line);
            printf("Type 'help' for available commands.\n");
        }

        /* Free dynamically allocated memory */
        free(line);
    }

    printf("Goodbye from Cloud Administration Shell!\n");

    return 0;
}
