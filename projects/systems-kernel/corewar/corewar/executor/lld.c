/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** lld.c
*/

#include "lib.h"

void lld_c(pool_t *pool, prog_t *prog)
{
    int address = select_correct_address(prog->address + prog->process->pc);
    int offset = 34;
    int register_id = 3;

    int i;
    for (i = 0; i < REG_SIZE; i++) {
        prog->process->reg[register_id] = pool->map[select_correct_address
        (address + offset + i)];
        add_pc(&(prog->process->pc), 1);
    }

    prog->carry = (prog->process->reg[register_id] == 0) ? 1 : 0;
}
