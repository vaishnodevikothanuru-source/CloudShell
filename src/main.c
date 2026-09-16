#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"

int main()
{
    char *line;
    char **tokens;
    int i;

    printf("=========================================\n");
    printf("      %s Version %s\n", SHELL_NAME, VERSION);
    printf("=========================================\n");
    printf("Cloud Administration Command Parser\n");
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

        printf("\nParsed Cloud Command:\n");

        for (i = 0; tokens[i] != NULL; i++)
        {
            printf("argv[%d] = %s\n", i, tokens[i]);
        }

        printf("\n");

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye from Cloud Administration Shell!\n");

    return 0;
}
