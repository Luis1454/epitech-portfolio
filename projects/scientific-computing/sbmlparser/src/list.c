/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** list functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/mylist.h"

void append_ll_node(ll_t **head, char *str)
{
    ll_t *node = malloc(sizeof(ll_t));
    ll_t *tmp = *head;

    node->data = my_strdup(str);
    node->next = NULL;
    if (!(*head)) {
        *head = node;
        return;
    }
    for (; tmp && tmp->next; tmp = tmp->next);
    tmp->next = node;
}

void sort_ll(ll_t **head)
{
    ll_t *tmp = NULL;

    for (ll_t *ll_tmp = *head; ll_tmp; ll_tmp = ll_tmp->next)
        for (tmp = ll_tmp; tmp; tmp = tmp->next) {
            my_strcmp(ll_tmp->data, tmp->data) > 0
            ? my_swap((int *)&ll_tmp->data, (int *)&tmp->data) : 0;
        }
}
