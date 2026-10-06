/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** (prog_number)n_flag.c
*/

#include "lib.h"

int sub_manage_prog_number(pool_t *pool, char *memory, int nbr)
{
    if (my_strcmp(memory, "0") == 0) {
        pool->nb_prog = my_strdup(memory);
    } else {
        nbr = my_getnbr(memory, 0);
        if (nbr == 0) {
            my_putstr_error("Error: Invalid prog_number value.\n");
            return 84;
        }
        pool->nb_prog = my_strdup(memory);
    }
    return 0;
}

int manage_prog_number(pool_t *pool, char *memory)
{
    int nbr = -1;

    if (pool->nb_prog != 0) {
        my_putstr_error("Error: Invalid prog_number\n");
        return 0;
    }
    for (int i = 0; memory[i] != '\0'; i++) {
        if (memory[i] < '0' || memory[i] > '9') {
            my_putstr_error("Error: Invalid prog_number value.\n");
            return 84;
        }
    }
    sub_manage_prog_number(pool, memory, nbr);
    if (nbr % MEM_SIZE != 0) {
        my_putstr_error("Error: Invalid prog_number value.\n");
        return 84;
    }
    return 0;
}
