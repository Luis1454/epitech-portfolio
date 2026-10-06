/*
** EPITECH PROJECT, 2024
** list_b.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "list.h"

void *list_get_elem_at_front(list_t *list)
{
    return list ? list->value : NULL;
}

void *list_get_elem_at_back(list_t *list)
{
    list_t *tmp = list;

    if (tmp == NULL)
        return NULL;
    for (; tmp->next; tmp = tmp->next);
    return tmp->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    list_t *tmp = list;

    if (position >= list_get_size(list))
        return NULL;
    if (tmp == NULL)
        return NULL;
    for (unsigned int i = 0; i < position; i++) {
        if (tmp == NULL)
            return NULL;
        tmp = tmp->next;
    }
    return tmp->value;
}

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    *front_ptr = tmp->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    for (; tmp->next && tmp->next->next; tmp = tmp->next);
    free(tmp->next);
    tmp->next = NULL;
    return true;
}
