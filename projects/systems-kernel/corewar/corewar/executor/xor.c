/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** xor.c
*/

#include "lib.h"

void xor_c(pool_t *pool, prog_t *prog)
{
    int param1 = pool->map[(prog->process->pc + 2) % MEM_SIZE];
    int param2 = pool->map[(prog->process->pc + 3) % MEM_SIZE];
    int param3 = pool->map[(prog->process->pc + 4) % MEM_SIZE];

    int value1, value2;
    if (param1 >= 0 && param1 < REG_NUMBER)
        value1 = pool->prog->process->reg[param1];
    else
        value1 = 0;
    if (param2 >= 0 && param2 < REG_NUMBER)
        value2 = pool->prog->process->reg[param2];
    else
        value2 = 0;
    pool->prog->process->reg[param3] = value1 ^ value2;
    prog->carry = (pool->prog->process->reg[param3] == 0) ? 1 : 0;
    prog->process->pc = (prog->process->pc + 5) % MEM_SIZE;
}
