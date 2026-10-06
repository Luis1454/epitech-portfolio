/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** lldi.c
*/

#include "lib.h"

void lldi(pool_t *pool)
{
    int address = get_exec_address(pool->prog);
    int param1 = pool->map[select_correct_address(address + 2)];
    int param2 = pool->map[select_correct_address(address + 3)];
    int reg_index = pool->map[select_correct_address(address + 4)];
    int pc = pool->prog->process->pc;
    int s = pc + param1;
    int sum = s + param2;

    int ind_value = *(int*)(pool->map + s);

    int reg_value = *(int*)(pool->map + sum);
    pool->prog->process->reg[reg_index] = reg_value;

    pool->prog->carry = reg_value;
}
