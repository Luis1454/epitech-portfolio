/*
** EPITECH PROJECT, 2023
** env.c
** File description:
** env functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

int my_env(env_node_t *env)
{
    for (env_node_t *tmp = env; tmp; tmp = tmp->next)
        my_printf("%s=%s\n", tmp->name, tmp->value);
    return 0;
}

void free_env(env_node_t *env)
{
    env_node_t *tmp = NULL;

    while (env) {
        tmp = env;
        env = env->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
    }
}

int free_array_n(char **array, int n)
{
    if (array == NULL)
        return 1;
    for (int i = 0; i < n && array[i]; i++)
        if (array[i])
            free(array[i]);
    free(array);
    return 0;
}

int free_array(char **array)
{
    if (array == NULL)
        return 1;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return 0;
}
