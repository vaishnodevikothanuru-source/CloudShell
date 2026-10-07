#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/pipes.h"

void execute_pipe(char **cmd1, char **cmd2)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return;
    }

    /* First child process */
    pid_t pid1 = fork();

    if (pid1 == -1)
    {
        perror("fork");
        return;
    }

    if (pid1 == 0)
    {
        /* First command does not need read end */
        close(pipefd[0]);

        /* Send output to pipe */
        if (dup2(pipefd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]);

        /* Execute first command */
        execvp(cmd1[0], cmd1);

        perror("Cloud Administration Shell");
        exit(EXIT_FAILURE);
    }

    /* Second child process */
    pid_t pid2 = fork();

    if (pid2 == -1)
    {
        perror("fork");
        return;
    }

    if (pid2 == 0)
    {
        /* Second command does not need write end */
        close(pipefd[1]);

        /* Read input from pipe */
        if (dup2(pipefd[0], STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        close(pipefd[0]);

        /* Execute second command */
        execvp(cmd2[0], cmd2);

        perror("Cloud Administration Shell");
        exit(EXIT_FAILURE);
    }

    /* Parent does not need pipe ends */
    close(pipefd[0]);
    close(pipefd[1]);

    /* Wait for both child processes */
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
