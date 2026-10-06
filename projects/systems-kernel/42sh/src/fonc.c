/*
** EPITECH PROJECT, 2023
** fonc.c
** File description:
** functions
*/
#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

int exit_shell(env_node_t *env, int status, char *input)
{
    free(input);
    free_env(env);
    return isatty(0) ? ERR_CODE_ : status;
}

void clear_str(char **str)
{
    char **split = my_str_to_array(*str, " \t", "");

    if (split == NULL)
        return;
    free(*str);
    *str = my_strdup(split[0]);
    free_array(split);
}
