/*
** EPITECH PROJECT, 2022
** my_delete_nodes.c
** File description:
** delete all nodes equals to a data
*/

#include "../../include/my.h"
#include "../../include/mylist.h"

linked_list_t *remove_node(linked_list_t *head,
linked_list_t *node, linked_list_t *prev)
{
    if (prev != NULL)
        prev->next = node->next;
    else
        head = node->next;
    free(node);
    return head;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int(*cmp)())
{
    linked_list_t *head = *begin;
    linked_list_t *prev = NULL;

    for (; *begin != NULL; *begin = (*begin)->next) {
        if ((*cmp)((*begin)->data, data_ref) == 0)
            head = remove_node(head, *begin, prev);
        prev = *begin;
    }
    return 0;
}
