/*
** EPITECH PROJECT, 2024
** node.c
** File description:
** node functions
*/

#include "../include/my_nm.h"
#include "../include/flags.h"

void swap_nodes(sym_t *a, sym_t *b)
{
    sym_t tmp;

    tmp.name = a->name;
    tmp.type = a->type;
    tmp.value = a->value;
    a->name = b->name;
    a->type = b->type;
    a->value = b->value;
    b->name = tmp.name;
    b->type = tmp.type;
    b->value = tmp.value;
}

static void sub_sort(sym_t *tmp, sym_t *tmp2)
{
    if (compare(tmp->name, tmp2->name, "_") > 0)
        swap_nodes(tmp, tmp2);
}

void sort_symbols(sym_t **arr)
{
    sym_t *tmp = *arr;

    for (; tmp; tmp = tmp->next)
        for (sym_t *tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
            sub_sort(tmp, tmp2);
}

void add_node(sym_t **arr, sym_t node)
{
    sym_t *new = malloc(sizeof(sym_t));
    sym_t *tmp = *arr;

    *new = node;
    new->next = NULL;
    new->prev = NULL;
    if (!tmp) {
        *arr = new;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
    new->prev = tmp;
}
