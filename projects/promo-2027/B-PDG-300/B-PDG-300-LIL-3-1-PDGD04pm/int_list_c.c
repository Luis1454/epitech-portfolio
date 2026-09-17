/*
** EPITECH PROJECT, 2024
** int_list_c.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    return list ? list->value : 0;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    int_list_t *tmp = list;

    if (tmp == NULL)
        return 0;
    for (; tmp->next; tmp = tmp->next);
    return tmp->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t *tmp = list;

    if (tmp == NULL)
        return 0;
    for (unsigned int i = 0; i < position; i++) {
        if (tmp == NULL)
            return 0;
        tmp = tmp->next;
    }
    return tmp->value;
}
