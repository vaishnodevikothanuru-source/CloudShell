#include <stdio.h>
#include <string.h>

int main()
{
    char input[1024];

    printf("=========================================\n");
    printf("       Cloud Administration Shell\n");
    printf("=========================================\n");
    printf("Type 'help' to see available commands.\n\n");

    while (1)
    {
        printf("cloud-admin> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting Cloud Administration Shell...\n");
            break;
        }
        else if (strcmp(input, "help") == 0)
        {
            printf("\nAvailable Commands:\n");
            printf("help          - Show available commands\n");
            printf("list-vm       - List virtual machines\n");
            printf("start-vm      - Start a virtual machine\n");
            printf("stop-vm       - Stop a virtual machine\n");
            printf("server-status - Check server status\n");
            printf("list-storage  - List storage resources\n");
            printf("list-users    - List cloud users\n");
            printf("exit          - Exit the shell\n\n");
        }
        else if (strcmp(input, "list-vm") == 0)
        {
            printf("VM-01 : Running\n");
            printf("VM-02 : Stopped\n");
            printf("VM-03 : Running\n");
        }
        else if (strcmp(input, "start-vm") == 0)
        {
            printf("Virtual machine started successfully.\n");
        }
        else if (strcmp(input, "stop-vm") == 0)
        {
            printf("Virtual machine stopped successfully.\n");
        }
        else if (strcmp(input, "server-status") == 0)
        {
            printf("Cloud Server Status: ONLINE\n");
        }
        else if (strcmp(input, "list-storage") == 0)
        {
            printf("Storage-01 : 500 GB\n");
            printf("Storage-02 : 1 TB\n");
        }
        else if (strcmp(input, "list-users") == 0)
        {
            printf("Admin\n");
            printf("Developer\n");
            printf("Guest\n");
        }
        else
        {
            printf("Unknown command: %s\n", input);
            printf("Type 'help' for available commands.\n");
        }
    }

    return 0;
}
