/*
** EPITECH PROJECT, 2024
** ex4.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "list.h"

bool list_is_empty(list_t *list)
{
    return list == NULL;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = *front_ptr;

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

static bool sub_list_add_elem_at_position(list_t **front_ptr, list_t *tmp,
    list_t *new, unsigned int position)
{
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

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    list_t *new = NULL;
    list_t *tmp = *front_ptr;

    if (position > list_get_size(*front_ptr))
        return false;
    new = malloc(sizeof(list_t));
    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    return sub_list_add_elem_at_position(front_ptr, tmp, new, position);
}
