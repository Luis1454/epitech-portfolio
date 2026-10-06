/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** or.c
*/

#include "asm_corewar.h"

int or_c(char **command, int fd)
{
    int idx = 0x07;
    int arg[3] = {0, 0, 0};

    arg[3] = register_f(command[3], 1);
    if (command[1] == NULL || command[2] == NULL || command[3] == NULL ||
    arg[0] == 0)
        return 84;
    if (register_f(command[1], 1) == 1 && register_f(command[2], 1) == 1)
        return and_r_r(command, fd, idx );
    if (register_f(command[1], 1) == 1 && direct(command[2], 1) == 1)
        return and_r_d(command, fd, idx );
    if (register_f(command[1], 1) == 1 && indirect(command[2], 1) == 1)
        return and_r_i(command, fd, idx );
    if (direct(command[1], 1) == 1 && register_f(command[2], 1) == 1)
        return and_d_r(command, fd, idx );
    if (direct(command[1], 1) == 1 && direct(command[2], 1) == 1)
        return and_d_d(command, fd, idx );
    if (direct(command[1], 1) == 1 && indirect(command[2], 1) == 1)
        return and_d_i(command, fd, idx );
    return and_2(command, fd, idx );
}
