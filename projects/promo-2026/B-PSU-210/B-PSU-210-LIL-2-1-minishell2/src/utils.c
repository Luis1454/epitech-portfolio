/*
** EPITECH PROJECT, 2021
** utls.c
** File description:
** utils file for minishell1
*/

#include "../includes/my.h"
#include "../includes/minishell.h"

void print_error(Env *env, char *cmd, char *msg, char *end)
{
    my_putstr(env->shell);
    my_putstr(": ");
    my_putstr(cmd);
    my_putstr(": ");
    my_putstr(msg);
    my_putstr(end);
}

int check_setenv(Env *env)
{
    if (my_arrlen(env->cmd) > 3) {
        my_putstr("unsetenv: Too many arguments.\n");
        return 0;
    }
    if (my_arrlen(env->cmd) > 1
    && !char_is_alpha(env->cmd[1][0]) && env->cmd[1][0] != '_') {
        my_putstr("setenv: Variable name must be a letter.\n");
        return 0;
    }
    my_setenv(env, env->cmd[1], env->cmd[2], my_arrlen(env->cmd));
    return 1;
}

int check_unsetenv(Env *env)
{
    if (my_arrlen(env->cmd) < 2) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 0;
    }
    my_unsetenv(env, env->cmd[1]);
    return 1;
}

void check_args(Env *env)
{
    if (are_equals(env->cmd[0], "setenv"))
        check_setenv(env);
    else if (are_equals(env->cmd[0], "unsetenv"))
        check_unsetenv(env);
}

int var_exist(Env *env, char *var)
{
    Node *tmp = env->head;

    for (; tmp != NULL && !are_equals(tmp->var, var); tmp = tmp->next);
    return tmp != NULL;
}
