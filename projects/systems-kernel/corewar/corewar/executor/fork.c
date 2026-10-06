/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** fork.c
*/

#include "lib.h"

void set_name_comment_registre(prog_t *prog, int address, int reg)
{
    int value = prog->process->reg[reg];
    int i = 0;

    while (i < REG_SIZE) {
        prog->process->reg[reg] = value >> (8 * (REG_SIZE - i - 1));
        i++;
    }
}

void sub_fork(pool_t *pool, int newAddress, prog_t *newProg)
{
    process_t *newProcess = (process_t *)malloc(sizeof(process_t));
    newProcess->reg = NULL;
    newProcess->pos = 0;
    newProcess->pc = newAddress;
    newProcess->next = NULL;
    newProg->process = newProcess;
    newProg = pool->prog;
    pool->prog = newProg;
    pool->nb_prog++;
    my_printf("New program created with ID: %d\n", newProg->id);
}

int fork(pool_t *pool, prog_t *prog)
{
    int parameter = 34;
    int newAddress = prog->process->pc + (parameter % IDX_MOD);

    prog_t *newProg = (prog_t *)malloc(sizeof(prog_t));
    newProg->id = pool->nb_prog + 1;
    newProg->head = 0;
    newProg->live = 0;
    newProg->carry = prog->carry;
    newProg->nb_live = prog->nb_live;
    newProg->address = newAddress;
    newProg->load_address = 0;
    newProg->last_alive = NULL;
    newProg->last_alive_id = 0;
    sub_fork(pool, newAddress, newProg);
    return 0;
}

int lfork(pool_t *pool, prog_t *prog)
{
    int parameter = 34;
    int newAddress = prog->process->pc + parameter;

    prog_t *newProg = (prog_t *)malloc(sizeof(prog_t));
    newProg->id = pool->nb_prog + 1;
    newProg->head = 0;
    newProg->live = 0;
    newProg->carry = prog->carry;
    newProg->nb_live = prog->nb_live;
    newProg->address = newAddress;
    newProg->load_address = 0;
    newProg->last_alive = NULL;
    newProg->last_alive_id = 0;
    sub_fork(pool, newAddress, newProg);
    return 0;
}
