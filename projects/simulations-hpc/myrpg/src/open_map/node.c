/*
** EPITECH PROJECT, 2023
** node.c
** File description:
** node functions
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"
#include "../../include/mylist.h"
#include "../../include/my_macro_abs.h"

int add_node(list_t **list, sfVector2i pos)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL)
        return 1;
    new->pos = pos;
    new->next = *list;
    *list = new;
    return 0;
}

int remove_last_node(list_t **list)
{
    list_t *tmp = *list;

    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return 0;
}

int len_list(list_t *list)
{
    int len = 0;

    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

linked_list_t *create_node(void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void append_node(linked_list_t **head, void *data)
{
    linked_list_t *node = create_node(data);
    linked_list_t *tmp = *head;

    if (!node)
        return;
    if (!*head) {
        *head = node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}
