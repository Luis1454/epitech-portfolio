/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** st.c
*/

#include "lib.h"

int st_c(pool_t *pool, prog_t *prog)
{
    int reg_index = *(prog->process->reg);
    int second_arg = *(prog->process->reg + 1);

    if (second_arg >= REG_SIZE) {
        my_putstr_error("Invalid register index\n");
        return -1;
    }

    int address = (prog->process->pc + (second_arg % IDX_MOD)) % IDX_MOD;

    if (address >= pool->total_cycle) {
        my_putstr_error("Invalid address\n");
        return -1;
    }
    pool->map[address] = *(prog->process->reg + reg_index);
    return 0;
}
