/*
** EPITECH PROJECT, 2021
** env.c
** File description:
** env file for minishell1
*/

#include "../includes/my.h"
#include "../includes/minishell.h"

void my_env(Env *env)
{
    Node *tmp = env->head;

    for (; tmp != NULL; tmp = tmp->next) {
        my_putstr(tmp->var);
        my_putchar(61);
        if (tmp->val != NULL)
            my_putstr(tmp->val);
        my_putchar('\n');
    }
}

void get_env_len(Env *env)
{
    Node *tmp = env->head;
    int i = 1;

    for (; tmp != NULL; tmp = tmp->next, i++);
    env->len = i;
}

int my_setenv(Env *env, char *var, char *val, int nb)
{
    if (nb == 1) {
        my_env(env);
        return 1;
    }
    if (var_exist(env, var))
        edit_node(env, var, val);
    else {
        add_node(env, var, val);
        get_env_len(env);
    }
    return 1;
}

int my_unsetenv(Env *env, char *var)
{
    Node *tmp = env->head;
    Node *n;

    for (; tmp->next != NULL && !are_equals(tmp->next->var, var);
    tmp = tmp->next);
    if (are_equals(tmp->next->var, var)) {
        n = tmp->next;
        tmp->next = tmp->next->next;
        free(n);
    } else
        return 0;
    return 1;
}

void my_getenv(Env *env)
{
    int n;
    char *var;
    char *val;

    for (int i = 0; i < env->len; i++) {
        for (n = 0; env->arr[i][n] != 61; n++);
        var = parse_str(env->arr[i], env->arr[i][0], env->arr[i][n], 0);
        val = parse_str(env->arr[i], env->arr[i][n + 1], 0, n);
        i ? add_node(env, var, val) : init_node(env, var, val);
    }
    get_prompt(env);
}
