#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"
#include "../include/signals.h"
#include "../include/pipes.h"

/* Tokenize one side of a pipe */
static void tokenize(char *str, char **argv)
{
    int i = 0;

    char *token = strtok(str, " \t\n");

    while (token != NULL)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t\n");
    }

    argv[i] = NULL;
}

int main()
{
    char *line;
    char **tokens;

    /* Initialize signal handling */
    initialize_signals();

    printf("=========================================\n");
    printf("      %s Version %s\n", SHELL_NAME, VERSION);
    printf("=========================================\n");
    printf("        CLOUD ADMINISTRATION SHELL\n");
    printf("=========================================\n");
    printf("Pipe and IPC support enabled.\n");
    printf("Type 'help' to see available commands.\n\n");

    while (1)
    {
        printf("cloud-admin> ");

        line = read_line();

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        /*
         * Check whether the command contains a pipe
         */
        if (strchr(line, '|') != NULL)
        {
            char *argv1[64];
            char *argv2[64];

            char *left = strtok(line, "|");
            char *right = strtok(NULL, "|");

            if (left == NULL || right == NULL)
            {
                printf("Invalid pipe command.\n");
                free(line);
                continue;
            }

            tokenize(left, argv1);
            tokenize(right, argv2);

            if (argv1[0] == NULL || argv2[0] == NULL)
            {
                printf("Invalid pipe command.\n");
                free(line);
                continue;
            }

            execute_pipe(argv1, argv2);
        }
        else
        {
            /*
             * Normal command
             */
            tokens = parse_line(line);

            if (tokens[0] == NULL)
            {
                free_tokens(tokens);
                free(line);
                continue;
            }

            /*
             * Check built-in commands first
             */
            if (execute_builtin(tokens) == 0)
            {
                execute(tokens);
            }

            free_tokens(tokens);
        }

        free(line);
    }

    printf("\nGoodbye from Cloud Administration Shell!\n");

    return 0;
}
