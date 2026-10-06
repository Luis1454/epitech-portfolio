/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** and3.c
*/

#include "asm_corewar.h"

int and_i_i(char **command, int fd, int idx )
{
    int arg1 = revbytes(my_getnbr(command[1]));
    int arg2 = revbytes(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(3, 3, 1, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 4);
    write(fd, &arg2, 4);
    write(fd, &arg3, 1);
    return 0;
}
