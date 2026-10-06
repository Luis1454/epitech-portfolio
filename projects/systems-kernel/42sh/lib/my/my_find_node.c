/*
** EPITECH PROJECT, 2022
** my_find_node.c
** File description:
** find a node in a linked list
*/

#include "../../include/my.h"
#include "../../include/mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)())
{
    for (; begin != NULL; begin = begin->next)
        if ((*cmp)(begin->data, data_ref) == 0)
            return (linked_list_t *)begin;
    return NULL;
}

int is_sorted_list(read_list_t *node)
{
    for (; node->next->next != NULL; node = node->next)
        if (get_lower_str(node->data->d_name, node->next->data->d_name) > 0)
            return 0;
    return 1;
}
