/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** search_type.c
*/

#include "asm_corewar.h"

int encoded_type(int arg1, int arg2, int arg3, int arg4)
{
    int encoded = 0;

    encoded = encoded + (arg1 * 64);
    encoded = encoded + (arg2 * 16);
    encoded = encoded + (arg3 * 4);
    encoded = encoded + (arg4 * 1);
    return encoded;
}

int indirect(char *command, int nb_arg)
{
    int i = 0;

    if (command == NULL)
        return 84;
    for (i = 0; i < nb_arg; i++) {
        if (command[i] == DIRECT_CHAR || command[i] == 'r') {
            return 0;
        }
    }
    return 1;
}

int register_f(char *command, int nb_arg)
{
    int i = 0;

    if (command == NULL)
        return 84;
    for (i = 0; i < nb_arg; i++) {
        if (command[i] == 'r') {
            return 1;
        }
    }
    return 0;
}

int direct(char *command, int nb_arg)
{
    int i = 0;

    if (command == NULL)
        return 84;
    for (i = 0; i < nb_arg; i++) {
        if (command[i] == DIRECT_CHAR) {
            return 1;
        }
    }
    return 0;
}
