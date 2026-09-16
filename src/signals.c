#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

/* Handle Ctrl+C */
static void sigint_handler(int sig)
{
    (void)sig;

    printf("\nCloud Administration Shell: Press 'exit' to quit.\n");
    printf("cloud-admin> ");
    fflush(stdout);
}

/* Clean up completed child processes */
static void sigchld_handler(int sig)
{
    (void)sig;

    while (waitpid(-1, NULL, WNOHANG) > 0)
    {
        /* Remove completed child processes */
    }
}

/* Initialize signal handlers */
void initialize_signals(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGCHLD, sigchld_handler);
}
