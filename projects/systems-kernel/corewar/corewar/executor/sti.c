/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** sti.c
*/

#include "lib.h"

int get_index(int value, prog_t *prog, pool_t *pool)
{
    if (value >= 0 && value < REG_SIZE)
        return prog->process->reg[value];
    else
        return value;
}

char *my_memcpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

void sti(pool_t *pool, prog_t *prog)
{
    int reg_index = prog->process->reg[prog->process->pc + 1];
    int index1 = get_index(prog->process->reg[prog->process->pc + 2], prog,
    pool);
    int index2 = get_index(prog->process->reg[prog->process->pc + 3], prog,
    pool);
    int address = index1 + index2;

    my_memcpy(pool->map + address, &(prog->process->reg[reg_index]), REG_SIZE);

    prog->process->pc += 4;
}
