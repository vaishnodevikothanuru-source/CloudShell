#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int execute_builtin(char **args)
{
    char cwd[1024];

    if (args[0] == NULL)
    {
        return 1;
    }

    /* exit */
    if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting Cloud Administration Shell...\n");
        exit(EXIT_SUCCESS);
    }

    /* pwd */
    if (strcmp(args[0], "pwd") == 0)
    {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("Current Cloud Directory: %s\n", cwd);
        }
        else
        {
            perror("pwd");
        }

        return 1;
    }

    /* cd */
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            printf("Usage: cd directory\n");
        }
        else
        {
            if (chdir(args[1]) != 0)
            {
                perror("cd");
            }
        }

        return 1;
    }

    /* clear */
    if (strcmp(args[0], "clear") == 0)
    {
        system("clear");
        return 1;
    }

    /* help */
    if (strcmp(args[0], "help") == 0)
    {
        printf("\n");
        printf("=========================================\n");
        printf("     CLOUD ADMINISTRATION SHELL\n");
        printf("=========================================\n");

        printf("\nBuilt-in Commands:\n");
        printf("-----------------------------------------\n");
        printf("cd <directory>   - Change current directory\n");
        printf("pwd              - Show current directory\n");
        printf("clear            - Clear the terminal\n");
        printf("help             - Show available commands\n");
        printf("env              - Show environment variables\n");
        printf("exit             - Exit the shell\n");

        printf("\nCloud Administration Commands:\n");
        printf("-----------------------------------------\n");
        printf("list-vm          - List virtual machines\n");
        printf("start-vm         - Start a virtual machine\n");
        printf("stop-vm          - Stop a virtual machine\n");
        printf("server-status    - Check server status\n");
        printf("list-storage     - List storage resources\n");
        printf("list-users       - List cloud users\n");

        printf("\n");
        return 1;
    }

    /* env */
    if (strcmp(args[0], "env") == 0)
    {
        printf("\nCloud Shell Environment Variables:\n");
        printf("-----------------------------------------\n");

        printf("HOME   = %s\n", getenv("HOME"));
        printf("USER   = %s\n", getenv("USER"));
        printf("PATH   = %s\n", getenv("PATH"));
        printf("SHELL  = %s\n", getenv("SHELL"));
        printf("PWD    = %s\n", getenv("PWD"));

        printf("\n");
        return 1;
    }

    return 0;
}
