#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"

int main()
{
    char *line;
    char **tokens;

    printf("=========================================\n");
    printf("      %s Version %s\n", SHELL_NAME, VERSION);
    printf("=========================================\n");
    printf("Cloud Administration Shell\n");
    printf("Type Linux commands or 'exit' to quit.\n\n");

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

        execute(tokens);

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye from Cloud Administration Shell!\n");

    return 0;
}
