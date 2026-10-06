/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** and2.c
*/

#include "asm_corewar.h"

int and_d_r(char **command, int fd, int idx )
{
    int idx_label = rev_2_bit(find_label_w(command[2]));
    int arg1 = rev_2_bit(my_getnbr(command[1]));
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(2, 1, 1, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 2);
    write(fd, &arg2, 1);
    write(fd, &arg3, 1);
    return 0;
}

int and_d_d(char **command, int fd, int idx )
{
    int idx_label = rev_2_bit(find_label_w(command[2]));
    int idx_label2 = rev_2_bit(find_label_w(command[3]));
    int arg1 = rev_2_bit(my_getnbr(command[1]));
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(2, 1, 1, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    if (idx_label2 != 0)
        arg3 = rev_2_bit(idx_label2);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 2);
    write(fd, &arg2, 2);
    write(fd, &arg3, 1);
    return 0;
}

int and_d_i(char **command, int fd, int idx )
{
    int idx_label = rev_2_bit(find_label_w(command[2]));
    int arg1 = rev_2_bit(my_getnbr(command[1]));
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(2, 1, 1, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 2);
    write(fd, &arg2, 4);
    write(fd, &arg3, 1);
    return 0;
}

int and_i_r(char **command, int fd, int idx )
{
    int arg1 = revbytes(my_getnbr(command[1]));
    int arg2 = my_getnbr(command[2]);
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(3, 1, 1, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 4);
    write(fd, &arg2, 1);
    write(fd, &arg3, 1);
    return 0;
}

int and_i_d(char **command, int fd, int idx )
{
    int idx_label = rev_2_bit(find_label_w(command[2]));
    int arg1 = revbytes(my_getnbr(command[1]));
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(3, 2, 1, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 4);
    write(fd, &arg2, 2);
    write(fd, &arg3, 1);
    return 0;
}
