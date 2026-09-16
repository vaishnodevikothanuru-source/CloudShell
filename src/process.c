#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int execute(char **tokens)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        /* Child process */
        if (execvp(tokens[0], tokens) == -1)
        {
            perror("Cloud Administration Shell");
        }

        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /* Fork failed */
        perror("fork");
    }
    else
    {
        /* Parent process waits for child */
        do
        {
            waitpid(pid, &status, WUNTRACED);

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
