/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** sub.c
*/

#include "lib.h"

void sub_executor(pool_t *pool, prog_t *prog)
{
    int address = get_exec_address(prog);
    int reg1 = pool->map[select_correct_address(address + 2)];
    int reg2 = pool->map[select_correct_address(address + 3)];
    int reg3 = pool->map[select_correct_address(address + 4)];
    int result = reg2 - reg3;

    prog->process->reg[reg1] = result;
    if (result == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
    add_pc(&prog->process->pc, 5);
}
