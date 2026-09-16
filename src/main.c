#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"
#include "../include/signals.h"

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
    printf("Signal handling enabled.\n");
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

        tokens = parse_line(line);

        if (tokens[0] == NULL)
        {
            free_tokens(tokens);
            free(line);
            continue;
        }

        /*
         * Check for built-in commands first.
         * If not built-in, execute as an external command.
         */
        if (execute_builtin(tokens) == 0)
        {
            execute(tokens);
        }

        free_tokens(tokens);
        free(line);
    }

    printf("\nGoodbye from Cloud Administration Shell!\n");

    return 0;
}
