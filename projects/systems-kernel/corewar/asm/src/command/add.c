/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** add.c
*/

#include "asm_corewar.h"

int add(char **command, int fd)
{
    int idx = 0x04;
    int arg[3] = {0, 0, 0};
    int content = encoded_type(1, 1, 1, 0);

    if (command[1] == NULL || command[2] == NULL || command[3] == NULL)
        return 84;
    if (register_f(command[1], 1) == 1 && register_f(command[2], 1) == 1
    && register_f(command[3], 1) == 1) {
        write(fd, &idx, 1);
        write(fd, &content, 1);
        arg[0] = my_getnbr(command[1]);
        arg[1] = my_getnbr(command[2]);
        arg[2] = my_getnbr(command[3]);
        write(fd, &arg[0], 1);
        write(fd, &arg[1], 1);
        write(fd, &arg[2], 1);
    } else
        return 84;
    return 0;
}
