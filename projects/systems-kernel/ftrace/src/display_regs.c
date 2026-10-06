/*
** EPITECH PROJECT, 2023
** B-PSU-400-LIL-4-1-strace-alexis.salaun
** File description:
** display_regs.c
*/

#include "../include/display_regs.h"
#include "../include/syscall.h"

// static char *display_content_of_regs(pid_t child, unsigned long long data)
// {
//     char *content = malloc(32);
//     long data_value = 0;

//     if (content == NULL)
//         return NULL;
//     for (size_t i = 0; i < 32; ++i) {
//         data_value = ptrace(PTRACE_PEEKDATA, child, data + i, NULL);
//         if (data_value == -1) {
//             free(content);
//             return NULL;
//         }
//         content[i] = *(char *)&data_value;
//         if (content[i] == '\0')
//             break;
//     }
//     return content;
// }
static void display_regs_second_part(struct user_regs_struct *regs, int i)
{
    char buffer[32];

    if (i == 3) {
        snprintf(buffer, 32, "%llx", (unsigned long long) regs->r10);
        printf(", 0x%s", buffer);
    }
    if (i == 4) {
        snprintf(buffer, 32, "%llx", (unsigned long long)regs->r8);
        printf(", 0x%s", buffer);
    }
    if (i == 4) {
        snprintf(buffer, 32, "%llx", (unsigned long long) regs->r9);
        printf(", 0x%s", buffer);
    }
}

static void print_display_first_part(struct user_regs_struct *regs, int i)
{
    char buffer[32];

    if (i == 0) {
        snprintf(buffer, 32, "%llx",
            (unsigned long long)regs->rdi);
        if (buffer[0] == '0' && buffer[1] == '\0')
            printf("NULL");
        else
            printf("0x%s", buffer);
    }
    if (i == 1) {
        snprintf(buffer, 32, "%llx", (unsigned long long) regs->rsi);
        printf(", 0x%s", buffer);
    }
    if (i == 2) {
        snprintf(buffer, 32, "%llx", (unsigned long long) regs->rdx);
        printf(", 0x%s", buffer);
    }
}

void display_regs(struct user_regs_struct *regs, char *syscall_name)
{
    printf("%s(", syscall_name);
    for (int i = 0; i < table[regs->orig_rax].nb_args; ++i) {
        print_display_first_part(regs, i);
        display_regs_second_part(regs, i);
    }
}
