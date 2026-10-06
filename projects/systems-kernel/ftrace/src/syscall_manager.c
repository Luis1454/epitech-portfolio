/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** syscall_manager
*/

#include "../include/syscall_manager.h"
#include "../include/syscall.h"

int syscall_manager(ftrace_t *ftrace)
{
    int syscall_num = ftrace->regs.orig_rax;
    syscall_t syscall_info = table[syscall_num];

    if (syscall_info.name == NULL)
        return 0;
    if (syscall_info.id > 0) {
        printf("Syscall ");
        display_regs(&ftrace->regs, syscall_info.name);
        printf(") = 0x%llx\n", ftrace->regs.rax);
    } else
        printf("Syscall %s\n", syscall_info.name);
    return 0;
}
