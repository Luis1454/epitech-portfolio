/*
** EPITECH PROJECT, 2024
** int_list_d.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    *front_ptr = tmp->next;
    free(tmp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    for (; tmp->next && tmp->next->next; tmp = tmp->next);
    free(tmp->next);
    tmp->next = NULL;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *tmp = *front_ptr;
    int_list_t *tmp_b = NULL;

    if (tmp == NULL)
        return false;
    if (position == 0) {
        *front_ptr = tmp->next;
        free(tmp);
        return true;
    }
    for (unsigned int i = 0; i < position - 1; i++) {
        if (tmp == NULL)
            return false;
        tmp = tmp->next;
    }
    tmp_b = tmp->next;
    tmp->next = tmp_b->next;
    free(tmp_b);
    return true;
}
