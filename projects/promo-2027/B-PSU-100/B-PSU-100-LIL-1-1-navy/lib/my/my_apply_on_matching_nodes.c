/*
** EPITECH PROJECT, 2022
** my_apply_on_matching_nodes.c
** File description:
** edit nodes where a function return true
*/

#include "../../include/my.h"
#include "../../include/mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin,
int (*f)(void *), void const *data_ref, int (*cmp)(void const *, void const *))
{
    for (; begin != NULL; begin = begin->next)
        if ((*cmp)(begin->data, data_ref) == 0)
            (*f)(begin->data);
    return 0;
}
