/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** aff.c
*/

#include "lib.h"

int aff(char **command, int fd)
{
    int idx = 0x10;
    int arg[1] = {0};
    int content = encoded_type(1, 0, 0, 0);

    if (command[1] == NULL)
        return 84;
    if (register_f(command[1], 1) == 1) {
        write(fd, &idx, 1);
        write(fd, &content, 1);
        arg[0] = my_getnbr(command[1]);
        write(fd, &arg[0], 1);
    } else
        return 84;
    return 0;
}
