/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** live.c
*/

#include "asm_corewar.h"

int live(char **command, int fd)
{
    int idx = 0x01;
    int arg = 0;
    int dir = 0;
    int ind = 0;
    int reg = 0;

    if (command[1] == NULL )
        return 84;
    if (direct(command[1], 1) == 1 && indirect(command[1], 1) == 0 &&
    register_f(command[1], 1) == 0) {
        arg = my_getnbr(command[1]);
        write(fd, &idx, 1);
        arg = revbytes(arg);
        write(fd, &arg, sizeof(int));
    }
    return 0;
}
