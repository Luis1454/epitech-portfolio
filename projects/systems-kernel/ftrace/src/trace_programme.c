/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** trace_programme
*/

#include "../include/trace_programme.h"

int trace_programme(ftrace_t *ftrace)
{
    int sig = 0;
    unsigned long long previous_addr = 0;

    open_and_verif(ftrace, ftrace->binary_name);
    while (1) {
        ptrace(PTRACE_GETREGS, ftrace->pid, NULL, &ftrace->regs);
        sig = signal_manager(ftrace);
        if (sig != 0)
            return (sig - 1);
        if (ftrace->regs.orig_rax > 0 && ftrace->regs.orig_rax < 300)
            syscall_manager(ftrace);
        fonction_manager(ftrace, &previous_addr);
        if (ptrace(PTRACE_SINGLESTEP, ftrace->pid, NULL, NULL) == -1)
            return fonction_perror("ptrace");
        waitpid(ftrace->pid, &ftrace->status, 0);
    }
    return 0;
}
