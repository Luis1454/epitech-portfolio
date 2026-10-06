/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

void drop_quotes(char **str)
{
    char *tmp = NULL;

    if (!(*str))
        return;
    if ((*str)[0] == '"' || (*str)[0] == '\'') {
        tmp = my_strdup(&(*str)[1]);
        free(*str);
        *str = tmp;
    }
    if (my_strlen(*str) >= 2
    && ((*str)[my_strlen(*str) - 1] == '"'
    || (*str)[my_strlen(*str) - 1] == '\'')
    && (*str)[my_strlen(*str) - 2] != '\\')
        (*str)[my_strlen(*str) - 1] = 0;
}

int append_array(char ***arr, char *str)
{
    char **tmp = malloc(sizeof(char *) * (my_arrlen(*arr) + 2));

    if (tmp == NULL)
        return 1;
    tmp[0] = my_strdup(str);
    for (int i = 0; tmp[i]; i++)
        tmp[i + 1] = my_strdup((*arr)[i]);
    free(*arr);
    *arr = tmp;
    return 0;
}

int find_str(char *str, char **arr)
{
    for (int i = 0; arr[i]; i++)
        if (!my_strcmp(arr[i], str))
            return 1;
    return 0;
}

int my_alphanumlen(const char *str)
{
    int i = 0;

    for (; str[i] && (my_char_isalpha(str[i]) || my_char_isnum(str[i])); i++);
    return i;
}

void free_mem(env_node_t *env, char **split, char **args)
{
    env ? free_env(env) : 0;
    split ? free_array(split) : 0;
    args ? free_array(args) : 0;
}
