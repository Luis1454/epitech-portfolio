/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** signal_gestion
*/

#include "../include/signal_manager.h"

void sub_signal_gestion(ftrace_t *ftrace)
{
    int sig = 0;

    if (WIFSIGNALED(ftrace->status)) {
        sig = WTERMSIG(ftrace->status);
        printf("Process %d killed by signal %d", ftrace->pid, sig);
        switch (sig) {
            case SIGINT:
                printf(" (Interrupt)\n");
                break;
            case SIGILL:
                printf(" (Illegal instruction)\n");
                break;
            case SIGFPE:
                printf(" (Floating point exception)\n");
                break;
            default:
                printf("\n");
                break;
        }
    }
}

int signal_manager(ftrace_t *ftrace)
{
    if (WIFEXITED(ftrace->status)) {
        printf("Process %d exited with status %d\n",
        ftrace->pid, WEXITSTATUS(ftrace->status));
        printf("+++ exited with %d +++\n", WEXITSTATUS(ftrace->status));
        return (WEXITSTATUS(ftrace->status) + 1);
    }
    sub_signal_gestion(ftrace);
    return 0;
}
