/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** ld.c
*/

#include "asm_corewar.h"

void ld_d_r(char **command, int fd, int idx )
{
    int idx_label = revbytes(find_label_w(command[1]));
    int arg1 = revbytes(my_getnbr(command[1]));
    char arg2 = my_getnbr(command[2]);
    int content = encoded_type(2, 1, 0, 0);

    if (idx_label == 0) {
        write(fd, &idx, 1);
        write(fd, &content, 1);
        write(fd, &arg1, 4);
        write(fd, &arg2, 1);
        return;
    }
    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &idx_label, 4);
    write(fd, &arg2, 1);
    return;
}

void ld_i_r(char **command, int fd, int idx )
{
    int arg1 = my_getnbr(command[1]);
    int arg2 = my_getnbr(command[2]);
    int content = encoded_type(2, 1, 0, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 4);
    write(fd, &arg2, 1);
    return;
}

int ld_c(char **command, int fd)
{
    int idx = 0x02;
    int content = 0;
    int arg[2] = {0, 0};

    if (command[1] == NULL || command[2] == NULL)
        return 84;
    if (direct(command[1], 1) == 1 && register_f(command[2], 1) == 1) {
        ld_d_r(command, fd, idx );
    } else if (indirect(command[1], 1) == 1 && register_f(command[2], 1) == 1) {
        ld_i_r(command, fd, idx );
    } else
        return 84;
    return 0;
}
