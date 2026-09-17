/*
** EPITECH PROJECT, 2024
** list_c.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t *list)
{
    unsigned int i = 0;

    for (list_t *tmp = list; tmp; tmp = tmp->next)
        i++;
    return i;
}

bool sub_list_add_elem_at_position(list_t *tmp,
    list_t *tmp_b, unsigned int position)
{
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

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *tmp = *front_ptr;
    list_t *tmp_b = NULL;

    if (position >= list_get_size(*front_ptr))
        return false;
    if (tmp == NULL)
        return false;
    if (position == 0) {
        *front_ptr = tmp->next;
        free(tmp);
        return true;
    }
    return sub_list_add_elem_at_position(tmp, tmp_b, position);
}

void list_clear(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;

    while (tmp) {
        tmp = tmp->next;
        free(*front_ptr);
        *front_ptr = tmp;
    }
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (list_t *tmp = list; tmp; tmp = tmp->next)
        val_disp(tmp->value);
}
