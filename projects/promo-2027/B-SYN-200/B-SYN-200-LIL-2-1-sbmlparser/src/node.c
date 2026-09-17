/*
** EPITECH PROJECT, 2023
** node.c
** File description:
** node functions
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/my_macro_abs.h"

node_t *find_node(node_t *head, char *str)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->str, str))
            return tmp;
    }
    return NULL;
}

node_t *get_node_by_name(node_t *head, char *name)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, name))
            return tmp;
    return NULL;
}

void swap_nodes(node_t *a, node_t *b)
{
    my_swap((int *)&a->str, (int *)&b->str);
    my_swap((int *)&a->args, (int *)&b->args);
    my_swap((int *)&a->name, (int *)&b->name);
    my_swap((int *)&a->level, (int *)&b->level);
}

void append_node(node_t **head, char *str)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *head;
    int start = get_name_pos(str);
    int len = MIN(my_strlen_to(str, " "),
    my_strlen_to(str, ">")) - start;

    new->str = str;
    new->name = my_strndup(&str[start], len);
    new->args = get_args(str);
    sort_args(&new->args);
    new->next = NULL;
    if (!(*head)) {
        new->level = 0;
        *head = new;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    new->level = tmp->level;
    tmp->next = new;
}

void free_nodes(node_t *head)
{
    node_t *tmp = head;
    args_t *next = NULL;

    for (; tmp; tmp = tmp->next) {
        tmp->str ? free(tmp->str) : 0;
        tmp->name ? free(tmp->name) : 0;
        for (args_t *arg = tmp->args; arg; arg = next) {
            arg->var ? free(arg->var) : 0;
            arg->value ? free(arg->value) : 0;
            next = arg->next;
            arg ? free(arg) : 0;
        }
    }
}
