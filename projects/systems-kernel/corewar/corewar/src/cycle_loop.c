/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** cycle_loop.c
*/

#include "lib.h"

void init_pool(pool_t **pool, int nb)
{
    (*pool)->nb_prog = nb;
    prog_t *prog = malloc(sizeof(prog_t) * nb);

    if (!prog) {
        return;
    }

    prog[0].id = 1;
    prog[0].live = TRUE;
    prog[0].carry = TRUE;
    add_process(&prog[0].process, 0, (int *){0});
    (*pool)->prog = prog;
}

int cycle_loop(pool_t *pool, int nb)
{
    init_pool(&pool, nb);

    for (int i = 0; i < 100; i++);
    return 0;
}
