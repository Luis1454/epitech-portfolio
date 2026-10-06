/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** start_tracer
*/

#include "../include/my_ftrace.h"

void trace_attach(char **av)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    execvp(av[1], &av[1]);
    exit(0);
}

/* If it's don't work try :
    ftrace->pid = pid;
    waitpid(ftrace->pid, &status, 0);
    if (ptrace(PTRACE_SETOPTIONS, ftrace->pid, 0, PTRACE_O_TRACEEXIT) == -1)
        return -1;
    if (ptrace(PTRACE_SINGLESTEP, ftrace->pid, 0, 0) == -1)
        return -1;
*/
int initialize_tracer(ftrace_t *ftrace, pid_t pid)
{
    ftrace->status = 0;
    ftrace->pid = pid;
    if (ftrace->pid == -1)
        return -1;
    waitpid(ftrace->pid, &ftrace->status, 0);
    return 0;
}

int start_tracer(ftrace_t *ftrace, char **av)
{
    pid_t pid;

    pid = fork();
    ftrace->binary_name = av[1];
    if (pid == 0)
        trace_attach(av);
    else {
        if (initialize_tracer(ftrace, pid) == -1)
            return 84;
    }
    return 0;
}
