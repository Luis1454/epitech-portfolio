/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** aff.c
*/

#include "lib.h"

int my_aff(pool_t *pool, prog_t *prog)
{
    unsigned char *map = &(pool->map);
    pool->prog->process->pc = (pool->prog->process->pc + 2) % MEM_SIZE;
    if (map[pool->prog->process->pc] <= REG_NUMBER) {
        my_putchar(pool->prog->process->reg[map[pool->prog->process->pc]] %
        256);
    }
    pool->prog->process->pc = (pool->prog->process->pc + 1) % MEM_SIZE;
    return 0;
}
