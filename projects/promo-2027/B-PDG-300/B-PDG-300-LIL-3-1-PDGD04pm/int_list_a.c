/*
** EPITECH PROJECT, 2024
** int_list_a.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new = malloc(sizeof(int_list_t));
    int_list_t *tmp = *front_ptr;

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new;
        return true;
    }
    for (; tmp && tmp->next; tmp = tmp->next);
    tmp->next = new;
    return true;
}

void int_list_dump(int_list_t *list)
{
    for (int_list_t *tmp = list; tmp; tmp = tmp->next)
        printf("%d\n", tmp->value);
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int i = 0;

    for (int_list_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}

bool int_list_is_empty(int_list_t *list)
{
    return list == NULL;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *tmp = *front_ptr;

    while (tmp) {
        tmp = tmp->next;
        free(*front_ptr);
        *front_ptr = tmp;
    }
}
