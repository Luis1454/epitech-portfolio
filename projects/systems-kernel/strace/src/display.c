/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** display
*/

#include "../include/strace.h"

unsigned char *get_value(pid_t pid, void *value, size_t size)
{
    unsigned char *str = malloc(size + 1);
    long data = 0;
    size_t i = 0;

    memset(str, 0, size + 1);
    for (i = 0; i < size; i += sizeof(unsigned char)) {
        data = ptrace(PTRACE_PEEKDATA, pid, value + i, NULL);
        if (data < 0) {
            free(str);
            return NULL;
        }
        memcpy(str + i, &data, sizeof(unsigned char));
    }
    return str;
}

unsigned int print_addr(void *addr, int comma, args_t cmd)
{
    unsigned char *str = get_value(cmd.pid, addr, cmd.size);
    unsigned int n = 0;

    if (cmd.arg_s && str) {
        n = dprintf(1, "%s\"%s\"", comma ? ", " : "", str);
        if (str)
            free(str);
        return n;
    }
    if (!addr) {
        if (str)
            free(str);
        return dprintf(1, "%sNULL", comma ? ", " : "");
    }
    n = dprintf(1, "%s%p", comma ? ", " : "", addr);
    if (str)
        free(str);
    return n;
}

unsigned int display_arg(int i, reg_t regs, args_t cmd)
{
    switch (i) {
        case 0:
            return print_addr((void *)regs.rdi, 0, cmd);
        case 1:
            return print_addr((void *)regs.rsi, 1, cmd);
        case 2:
            return print_addr((void *)regs.rdx, 1, cmd);
        case 3:
            return print_addr((void *)regs.r10, 1, cmd);
        case 4:
            return print_addr((void *)regs.r8, 1, cmd);
        case 5:
            return print_addr((void *)regs.r9, 1, cmd);
        default:
            return 0;
    }
}

void display_args(reg_t args, syscall_t info, args_t cmd)
{
    int i = 0;

    for (i = 0; i < info.nb_args; i++)
        display_arg(i, args, cmd);
}

int handle_cmd_failure(reg_t regs)
{
    if ((long)regs.rax < 0) {
        dprintf(1, ") = -1 ");
        switch (-regs.rax) {
            case ENOENT:
                dprintf(1, "ENOENT ");
                break;
            case EACCES:
                dprintf(1, "EACCES ");
                break;
            case EINVAL:
                dprintf(1, "EINVAL ");
                break;
            default:
                dprintf(1, "Unknown error (%i) ", (int)regs.rax);
                break;
        }
        dprintf(1, "(%s)\n", strerror(-regs.rax));
        return 1;
    }
    return 0;
}
