/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** get functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

char *get_env_value(env_node_t *env_list, char *name)
{
    for (env_node_t *tmp = env_list; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, name))
            return tmp->value;
    return NULL;
}

char **get_paths(env_node_t *env)
{
    char **paths = NULL;
    char *path = get_env_value(env, "PATH");

    if (path == NULL)
        return NULL;
    paths = my_str_to_array(path, ":", "");
    return paths;
}

char *get_abs_path(void)
{
    char *path = malloc(sizeof(char) * 4096);

    if (!path)
        return NULL;
    getcwd(path, 4096);
    return path;
}

char **get_env(env_node_t *env)
{
    char **raw = NULL;
    int size = 0;
    int len = 0;

    for (env_node_t *tmp = env; tmp; tmp = tmp->next, len++);
    raw = malloc(sizeof(char *) * (len + 1));
    if (!raw)
        return NULL;
    for (int i = 0; i < len; i++) {
        size = my_strlen(env->name);
        raw[i] = malloc(sizeof(char) * (size + my_strlen(env->value) + 2));
        if (!raw[i])
            return NULL;
        my_strcpy(raw[i], env->name);
        raw[i][size] = '=';
        my_strcpy(&raw[i][size + 1], env->value);
        env = env->next;
    }
    raw[len] = NULL;
    return raw;
}

char *skip_all_chars(char *str, char c)
{
    int len = my_strlen(str);
    int i = len - 1;

    if (i < 0 || len <= 1)
        return str;
    while (str[--i] != c && i >= 0);
    return &str[i + 1];
}
