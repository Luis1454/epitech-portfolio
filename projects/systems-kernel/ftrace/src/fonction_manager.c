/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** fonction_manager
*/

#include "../include/fonction_manager.h"

int open_and_verif(ftrace_t *ftrace, char *filename)
{
    ftrace->elf.fd = open(filename, O_RDONLY);
    if (ftrace->elf.fd < 0) {
        perror("open");
        return -1;
    }
    if ((elf_version(EV_CURRENT)) == EV_NONE) {
        perror("elf_version");
        close(ftrace->elf.fd);
        return -1;
    }
    return 0;
}

int fonction_manager(ftrace_t *ftrace, unsigned long long *previous_addr)
{
    char *func_name;

    ptrace(PTRACE_PEEKTEXT, ftrace->pid, ftrace->regs.rip, NULL);
    if (*(unsigned char *)(&ftrace->regs.rip) == OP_CODE) {
        func_name = get_function_name(ftrace, ftrace->regs.rip);
        if (ftrace->regs.rip != *previous_addr && func_name != NULL) {
            printf(ENTERING_FUNCTION, func_name, ftrace->regs.rip);
            *previous_addr = ftrace->regs.rip;
            printf(LEAVING_FUNCTION, func_name);
            free(func_name);
        }
    }
    return 0;
}
