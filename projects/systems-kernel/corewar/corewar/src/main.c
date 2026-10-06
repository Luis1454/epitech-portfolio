/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** main.c
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

int *my_regdup(int *reg, int size)
{
    int *new_reg = malloc(sizeof(int) * size);
    if (reg == NULL) {
        return NULL;
    }
    if (!new_reg)
        return NULL;
    for (int i = 0; i < size; i++)
        new_reg[i] = reg[i];
    return new_reg;
}

void add_process(process_t **process, int pos, int *reg)
{
    process_t *tmp = malloc(sizeof(process_t));

    if (!tmp)
        return;
    tmp->pos = pos;
    tmp->pc = 0;
    tmp->next = NULL;
    tmp->reg = my_regdup(reg, REG_NUMBER);
    if (!tmp->reg)
        return free(tmp);
    if (!(*process)) {
        *process = tmp;
        return;
    }
    for (process_t *p = *process; p; p = p->next)
        if (!p->next) {
            p->next = tmp;
            return;
        }
}

int main(int ac, char **av)
{
    ac = ac;
    av = av;
    if (parse_arguments(ac, av))
        return 84;
    return 0;
}
