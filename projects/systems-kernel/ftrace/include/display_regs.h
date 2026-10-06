/*
** EPITECH PROJECT, 2024
** B-PSU-400-LIL-4-1-ftrace-alexis.salaun
** File description:
** display_regs
*/

#ifndef DISPLAY_REGS_H_
    #define DISPLAY_REGS_H_

    #include <sys/user.h>
    #include <stdio.h>

void display_regs(struct user_regs_struct *regs, char *syscall_name);

#endif /* !DISPLAY_REGS_H_ */
