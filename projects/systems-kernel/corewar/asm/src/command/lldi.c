/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** lldi.c
*/

#include "lib.h"

void lldi_r_r(char **command, int fd)
{
    int idx = 0x0e;
    int content = encoded_type(1, 1, 1, 0);
    int arg[3] = {0};

    write(fd, &idx, 1);
    write(fd, &content, 1);
    arg[0] = my_getnbr(command[1]);
    arg[1] = my_getnbr(command[2]);
    arg[2] = my_getnbr(command[3]);
    write(fd, &arg[0], 1);
    write(fd, &arg[1], 1);
    write(fd, &arg[2], 1);
}

void lldi_r_i(char **command, int fd)
{
    int idx = 0x0e;
    int content = encoded_type(1, 1, 1, 0);
    int arg[3] = {0};

    write(fd, &idx, 1);
    write(fd, &content, 1);
    arg[0] = my_getnbr(command[1]);
    arg[1] = my_getnbr(command[2]);
    arg[2] = my_getnbr(command[3]);
    write(fd, &arg[0], 1);
    write(fd, &arg[1], 2);
    write(fd, &arg[2], 1);
}

void lldi_i_r(char **command, int fd)
{
    int idx = 0x0e;
    int content = encoded_type(1, 1, 1, 0);
    int arg[3] = {0};

    write(fd, &idx, 1);
    write(fd, &content, 1);
    arg[0] = my_getnbr(command[1]);
    arg[1] = my_getnbr(command[2]);
    arg[2] = my_getnbr(command[3]);
    write(fd, &arg[0], 2);
    write(fd, &arg[1], 1);
    write(fd, &arg[2], 1);
}

int lldi(char **command, int fd)
{
    int idx = 0x0e;
    int content = 0;

    if (command[1] == NULL || command[2] == NULL || command[3] == NULL)
        return 84;
    if (register_f(command[1], 1) == 1 && register_f(command[2], 1) == 1
    && register_f(command[3], 1) == 1) {
        lldi_r_r(command, fd);
    } else if (register_f(command[1], 1) == 1 && indirect(command[2], 1) == 1
    && register_f(command[3], 1) == 1) {
        lldi_r_i(command, fd);
        return 0;
    }
    if (indirect(command[1], 1) == 1 && register_f(command[2], 1) == 1
    && register_f(command[3], 1) == 1) {
        lldi_r_i(command, fd);
    } else
        return 84;
    return 0;
}
