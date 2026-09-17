/*
** EPITECH PROJECT, 2021
** linked_lists.c
** File description:
** linked lists assets
*/

#include "../includes/minishell.h"
#include "../includes/my.h"

int print_ll_str(Node *node)
{
    Node *tmp = node;

    if (tmp == NULL)
        return 0;
    for (; tmp != NULL; tmp = tmp->next) {
        my_putstr(tmp->var);
        my_putstr(" -> ");
        my_putstr(tmp->val);
        my_putchar('\n');
    }
    return 1;
}

int init_node(Env *env, char *var, char *val)
{
    env->head->var = var;
    env->head->val = val;
    env->head->next = NULL;
    env->first = env->head;
    return 1;
}

int add_node(Env *env, char *var, char *val)
{
    Node *new = malloc(sizeof(Node));
    Node *tmp = env->head;

    if (new == NULL)
        return 0;
    new->var = var;
    new->val = val;
    new->next = NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return 1;
}

int edit_node(Env *env, char *var, char *val)
{
    Node *tmp = env->head;

    for (; tmp != NULL; tmp = tmp->next)
        if (are_equals(tmp->var, var)) {
            tmp->var = var;
            tmp->val = val;
            return 1;
        }
    return 0;
}
