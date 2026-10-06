/*
** EPITECH PROJECT, 2023
** heap_node.c
** File description:
** construct the btree from a node_t array
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

static void sub_heap_node(node_t **head, node_t **tmp, node_t **new)
{
    for (*tmp = *head; (*tmp)->next && (*tmp)->next->byte.nb < (*new)->byte.nb;)
        (*tmp) = (*tmp)->next;
    (*new)->next = (*tmp)->next;
    (*tmp)->next = *new;
    (*head) = (*head)->next;
}

node_t *heap_node(node_t *head, int len)
{
    node_t *tmp = NULL;
    node_t *new = NULL;

    for (int i = 0; i < len - 1; i++) {
        tmp = head;
        head = head->next;
        new = malloc(sizeof(node_t));
        if (new == NULL)
            return head;
        new->byte.nb = tmp->byte.nb + head->byte.nb;
        new->byte.c = -1;
        new->left = tmp;
        new->right = head;
        new->next = NULL;
        sub_heap_node(&head, &tmp, &new);
    }
    return head;
}
