/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** sti2.c
*/

#include "asm_corewar.h"

int sti_i_d(char **command, int fd, int idx )
{
    int idx_label = find_label_w(command[3]);
    int arg1 = my_getnbr(command[1]);
    int arg2 = revbytes(my_getnbr(command[2]));
    int arg3 = rev_2_bit(my_getnbr(command[3]));
    int content = encoded_type(1, 2, 2, 0);

    if (idx_label != 0)
        arg3 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 4);
    write(fd, &arg3, 2);
    return 0;
}

int sti_i_r(char **command, int fd, int idx )
{
    int arg1 = my_getnbr(command[1]);
    int arg2 = revbytes(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(1, 2, 2, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 4);
    write(fd, &arg3, 1);
    return 0;
}
