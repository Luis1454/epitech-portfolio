/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** ldi.c
*/

#include "lib.h"
#include "asm_corewar.h"

int get_argument_size(char *arg)
{
    if (direct(arg, 1))
        return DIR_SIZE;
    else if (indirect(arg, 1))
        return IND_SIZE;
    else
        return 1;
}

int get_argument_value(char *arg)
{
    if (direct(arg, 1) || indirect(arg, 1))
        return my_getnbr(arg + 1);
    else
        return my_getnbr(arg);
}

int ldi(char **command, int fd)
{
    int idx = 0x0a;
    int arg[3] = {0, 0, 0};
    int content = encoded_type(7, 4, 1, 0);
    if (command[1] == NULL || command[2] == NULL || command[3] == NULL)
        return 84;
    if ((register_f(command[1], 1) == 1 || direct(command[1], 1) == 1 ||
        indirect(command[1], 1) == 1) &&
        (register_f(command[2], 1) == 1 || direct(command[2], 1) == 1) &&
        register_f(command[3], 1) == 1) {
        write(fd, &idx, 1);
        write(fd, &content, 1);
        arg[0] = get_argument_value(command[1]);
        arg[1] = get_argument_value(command[2]);
        arg[2] = my_getnbr(command[3]);
        write(fd, &arg[0], get_argument_size(command[1]));
        write(fd, &arg[1], get_argument_size(command[2]));
        write(fd, &arg[2], 1);
    } else
        return 84;
    return 0;
}
