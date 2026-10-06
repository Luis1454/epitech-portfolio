/*
** EPITECH PROJECT, 2022
** my_delete_nodes.c
** File description:
** delete all nodes equals to a data
*/

#include "../../include/my.h"
#include "../../include/mylist.h"
#include <stdlib.h>
#include <dirent.h>

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

int my_sort_list(linked_list_t **begin, int(*cmp)(void *, void *))
{
    linked_list_t *tmp = NULL;
    linked_list_t *tmp2 = NULL;

    for (tmp = *begin; tmp != NULL; tmp = tmp->next)
        for (tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
            (*cmp)(tmp->data, tmp2->data) > 0 ?
            my_swap((int *)tmp, (int *)tmp2) : 0;
    return 0;
}

void free_nodes(linked_list_t *list)
{
    linked_list_t *tmp = NULL;

    for (; list != NULL; list = tmp) {
        tmp = list->next;
        free(list);
    }
}
