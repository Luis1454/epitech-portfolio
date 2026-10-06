/*
** EPITECH PROJECT, 2023
** setenv.c
** File description:
** my_setenv and my_unsetenv functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

int my_unsetenv(char **args, env_node_t *env)
{
    int len = my_arrlen(args);

    if (len < 2)
        return !my_print_error("unsetenv: Too few arguments.\n");
    for (env_node_t *tmp = env; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, args[1])) {
            env = drop_node(env, tmp);
            return 0;
        }
    return 0;
}

static int sub_my_setenv(char **args, env_node_t *env, int len)
{
    char *var = NULL;

    if (len < 2)
        return my_env(env);
    if (len > 3 || (len == 3 && !my_strlen(args[2])))
        return !my_print_error("setenv: Too many arguments.\n");
    if (len == 3 && args[2][0] == '$') {
        var = get_env_value(env, &args[2][1]);
        if (var == NULL) {
            my_print_error(&args[2][1]);
            return !my_print_error(": Undefined variable.\n");
        }
        args[2] = var;
    }
    return -1;
}

int var_exist(env_node_t *env, char *var)
{
    for (env_node_t *tmp = env; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, var))
            return 1;
    return 0;
}

int my_setenv(char **args, env_node_t *env)
{
    int len = my_arrlen(args);
    int state = 0;

    if ((state = sub_my_setenv(args, env, len)) != -1)
        return state;
    for (env_node_t *tmp = env; tmp && len > 2; tmp = tmp->next)
        if (!my_strcmp(tmp->name, args[1])) {
            free(tmp->value);
            tmp->value = my_strdup(args[2]);
            return 0;
        }
    if (var_exist(env, args[1]))
        my_unsetenv(args, env);
    env = append_node(env, args[1], len == 2 ? "" : args[2]);
    return 0;
}
