/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** zjmp.c
*/

#include "lib.h"

void zjmp(pool_t *pool, prog_t *prog)
{
    if (prog->carry == 1) {
        int jump_index = prog->process->pc + (prog->address % IDX_MOD);
        add_pc(&(prog->process->pc), jump_index);
    } else {
        add_pc(&(prog->process->pc), 1);
    }
}
