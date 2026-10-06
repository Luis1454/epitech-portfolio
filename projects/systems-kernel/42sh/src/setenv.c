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

static int sub_my_setenv(char **args, env_node_t *env, int len, char *tmp)
{
    if (len > 3 || (len == 3 && !my_strlen(args[2])))
        return !my_print_error("setenv: Too many arguments.\n");
    if (!(tmp = malloc(sizeof(char) * (2048 + 1))))
        return !my_print_error("setenv: malloc failed.\n");
    tmp = my_memset(tmp, 0, 2048 + 1);
    for (int i = 0; args[2][i]; i++) {
        if (args[2][i] == '\\')
            continue;
        if (args[2][i] == '$' && !get_env_value(env, &args[2][i + 1]))
            return !my_print_error("setenv: Undefined variable.\n");
        if (args[2][i] == '$') {
            tmp = my_strcat(tmp, get_env_value(env, &args[2][i + 1]));
            i += my_alphanumlen(&args[2][i + 1]);
        } else
            tmp = my_strncat(tmp, &args[2][i], 1);
    }
    free(args[2]);
    args[2] = tmp;
    return -1;
}

int var_exist(env_node_t *env, const char *var)
{
    for (env_node_t *tmp = env; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, var))
            return 1;
    return 0;
}

int check_var(const char *var)
{
    if (!my_char_isalpha(var[0]) && var[0] != '_') {
        my_print_error("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; var[i]; i++) {
        if (!my_char_isalpha(var[i])
        && !my_char_isnum(var[i]) && var[i] != '_') {
            my_print_error("setenv: Variable name must only contain ");
            my_print_error("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int my_setenv(char **args, env_node_t *env)
{
    int len = my_arrlen(args);
    int state = 0;

    if (len > 1 && check_var(args[1]))
        return 1;
    if (len < 2)
        return my_env(env);
    args[2] = len == 2 ? my_strdup("") : args[2];
    if ((state = sub_my_setenv(args, env, len, NULL)) != -1)
        return state;
    for (env_node_t *tmp = env; tmp && len > 2; tmp = tmp->next)
        if (!my_strcmp(tmp->name, args[1])) {
            free(tmp->value);
            tmp->value = my_strdup(args[2]);
            return 0;
        }
    if (var_exist(env, args[1]))
        my_unsetenv(args, env);
    env = append_node(env, args[1], args[2]);
    return 0;
}
