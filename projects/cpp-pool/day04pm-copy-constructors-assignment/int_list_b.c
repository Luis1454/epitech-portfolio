/*
** EPITECH PROJECT, 2024
** int_list_b.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new = malloc(sizeof(int_list_t));

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr,
    int elem, unsigned int position)
{
    int_list_t *new = malloc(sizeof(int_list_t));
    int_list_t *tmp = *front_ptr;

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    if (*front_ptr == NULL || !position) {
        new->next = *front_ptr != NULL ? *front_ptr : NULL;
        *front_ptr = new;
        return true;
    }
    for (unsigned int i = 0; i < position - 1; i++) {
        if (tmp == NULL)
            return false;
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
    return true;
}
