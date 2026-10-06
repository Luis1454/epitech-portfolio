/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** live.c
*/

#include "lib.h"
void reset_live(pool_t *pool)
{
    for (int i = 0; i < pool->nb_prog; i++)
        pool->prog[i].live = 0;
}

int check_live(pool_t *pool)
{
    int nb_live = 0;

    for (int i = 0; i < pool->nb_prog; i++)
        if (pool->prog[i].live == 1)
            nb_live++;
    return (nb_live);
}

void check_cycle(pool_t *pool)
{
    if (pool->cycle == 0) {
        reset_live(pool);
        pool->cycle = CYCLE_TO_DIE;
    }
}

int check_is_alive(pool_t *pool)
{
    int nb_live = check_live(pool);

    if (nb_live >= NBR_LIVE) {
        pool->cycle -= CYCLE_DELTA;
        reset_live(pool);
    }
    return (nb_live);
}

int live(pool_t *pool, prog_t *prog)
{
    int address = get_exec_address(prog);
    int reg1 = pool->map[select_correct_address(address + 1)];
    int nb_live = check_is_alive(pool);

    prog->live = 1;
    pool->prog->last_alive = pool->nb_prog;
    pool->prog->nb_live++;
    my_printf("The player %d(%s) is alive.\n", prog->nb_live,
    prog->last_alive);
    add_pc(&prog->process->pc, 5);
    return (0);
}
