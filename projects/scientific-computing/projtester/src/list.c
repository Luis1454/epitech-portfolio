/*
** EPITECH PROJECT, 2023
** list.c
** File description:
** list functions
*/

#include "../include/my.h"
#include "../include/tester.h"

void free_tree(list_t *tree)
{
    list_t *tmp = NULL;

    for (; tree; tree = tree->next) {
        if (tmp)
            free(tmp);
        if (tree->child)
            free_tree(tree->child);
        free(tree->name);
        tmp = tree;
    }
    if (tmp)
        free(tmp);
}

list_t *get_node(list_t *list, char *name)
{
    for (; list; list = list->next)
        if (!my_strcmp(list->name, name))
            return list;
    return NULL;
}

void swap_nodes(list_t *a, list_t *b)
{
    list_t *tmp_child = a->child;
    char *tmp_name = a->name;

    a->child = b->child;
    a->name = b->name;
    b->child = tmp_child;
    b->name = tmp_name;
}

void sort_tree(list_t **list)
{
    for (list_t *tmp = *list; tmp; tmp = tmp->next)
        if (tmp->child)
            sort_tree(&tmp->child);
    for (list_t *tmp = *list; tmp; tmp = tmp->next)
        for (list_t *tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
            my_strcmp(tmp->name, tmp2->name) > 0
            ? swap_nodes(tmp, tmp2) : 0;
}

void append_node(list_t **list, char *name)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *list;

    if (!node)
        return;
    node->name = my_strdup(name);
    node->next = NULL;
    node->child = NULL;
    if (!tmp) {
        *list = node;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = node;
}
