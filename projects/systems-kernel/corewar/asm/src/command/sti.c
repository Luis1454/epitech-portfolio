/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** sti.c
*/

#include "asm_corewar.h"

int sti_r_r(char **command, int fd, int idx )
{
    int arg1 = my_getnbr(command[1]);
    int arg2 = my_getnbr(command[2]);
    int arg3 = my_getnbr(command[3]);
    int content = encoded_type(1, 1, 1, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 1);
    write(fd, &arg3, 1);
    return 0;
}

int sti_r_d(char **command, int fd, int idx )
{
    int idx_label = revbytes(find_label_w(command[3]));
    int arg1 = my_getnbr(command[1]);
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = rev_2_bit(my_getnbr(command[3]));
    int content = encoded_type(1, 1, 2, 0);

    if (idx_label != 0)
        arg3 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 1);
    write(fd, &arg3, 2);
    return 0;
}

int sti_d_r(char **command, int fd, int idx )
{
    int idx_label = rev_2_bit(find_label_w(command[2]));
    int arg1 = my_getnbr(command[1]);
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = rev_2_bit(my_getnbr(command[3]));
    int content = encoded_type(1, 2, 1, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 2);
    write(fd, &arg3, 1);
    return 0;
}

int sti_d_d(char **command, int fd, int idx )
{
    int idx_label = find_label_w(command[2]);
    int idx_label2 = find_label_w(command[3]);
    int arg1 = my_getnbr(command[1]);
    int arg2 = rev_2_bit(my_getnbr(command[2]));
    int arg3 = rev_2_bit(my_getnbr(command[3]));
    int content = encoded_type(1, 2, 2, 0);

    if (idx_label != 0)
        arg2 = rev_2_bit(idx_label);
    if (idx_label2 != 0)
        arg3 = rev_2_bit(idx_label2);
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 2);
    write(fd, &arg3, 2);
    return 0;
}

int sti(char **command, int fd)
{
    int idx = 0x0b;
    int arg[3] = {0, 0, 0};
    arg[0] = register_f(command[1], 1);

    if (command[1] == NULL || command[2] == NULL || command[3] == NULL ||
    arg[0] == 0)
        return 84;
    if (register_f(command[2], 1) == 1 && register_f(command[3], 1) == 1)
        return sti_r_r(command, fd, idx );
    if (register_f(command[2], 1) == 1 && direct(command[3], 1) == 1)
        return sti_r_d(command, fd, idx );
    if (direct(command[2], 1) == 1 && register_f(command[3], 1) == 1)
        return sti_d_r(command, fd, idx );
    if (direct(command[2], 1) == 1 && direct(command[3], 1) == 1)
        return sti_d_d(command, fd, idx );
    if (indirect(command[2], 1) == 1 && register_f(command[3], 1) == 1)
        return sti_i_r(command, fd, idx );
    if (indirect(command[2], 1) == 1 && direct(command[3], 1) == 1)
        return sti_i_d(command, fd, idx );
    return 0;
}
