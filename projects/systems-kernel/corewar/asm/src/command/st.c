/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** st.c
*/

#include "asm_corewar.h"

void st_r_r(char **command, int fd, int idx )
{
    int arg1 = my_getnbr(command[1]);
    int arg2 = my_getnbr(command[2]);
    int content = encoded_type(1, 1, 0, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 1);
    return;
}

void st_r_i(char **command, int fd, int idx )
{
    int arg1 = my_getnbr(command[1]);
    int arg2 = revbytes(my_getnbr(command[2]));
    int content = encoded_type(1, 3, 0, 0);

    write(fd, &idx, 1);
    write(fd, &content, 1);
    write(fd, &arg1, 1);
    write(fd, &arg2, 4);
    return;
}

int st_c(char **command, int fd)
{
    int idx = 0x03;
    int content = 0;
    int arg[2] = {0, 0};

    if (command[1] == NULL || command[2] == NULL)
        return 84;
    if (register_f(command[1], 1) == 1 && register_f(command[2], 1) == 1) {
        st_r_r(command, fd, idx );
    } else if (indirect(command[2], 1) == 1 && register_f(command[1], 1) == 1) {
        st_r_i(command, fd, idx );
    } else
        return 84;
    return 0;
}
