/*
** EPITECH PROJECT, 2023
** node.c
** File description:
** linked list functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/minishell.h"

env_node_t *init_env_list(char **env)
{
    env_node_t *env_list = NULL;
    char **env_split = NULL;

    for (int i = 0; env[i]; i++) {
        env_split = my_str_to_array(env[i], "=", "");
        if (env_split == NULL || env_split[0] == NULL
        || my_strlen(env[i]) < my_strlen(env_split[0]) + 1) {
            my_print_error("Error: env variable is not valid.\n");
            free_array(env_split);
            free_env(env_list);
            return NULL;
        }
        env_list = append_node(env_list, env_split[0],
        &env[i][my_strlen(env_split[0]) + 1]);
        free_array(env_split);
    }
    return env_list;
}

env_node_t *add_node(env_node_t *env_list, char *env)
{
    env_node_t *new_node = malloc(sizeof(env_node_t));
    char **env_split = my_str_to_array(env, "=", "");

    if (new_node == NULL)
        return NULL;
    new_node->name = my_strdup(env_split[0]);
    new_node->value = my_strdup(env_split[1]);
    new_node->next = env_list;
    free(env_split);
    return new_node;
}

env_node_t *append_node(env_node_t *env_list, char *var, char *value)
{
    env_node_t *new_node = malloc(sizeof(env_node_t));
    char **env_split = malloc(sizeof(char *) * 3);

    env_split[0] = my_strdup(var);
    env_split[1] = my_strdup(value);
    env_split[2] = NULL;
    if (new_node == NULL)
        return NULL;
    new_node->name = my_strdup(env_split[0]);
    new_node->value = my_strdup(env_split[1]);
    new_node->next = NULL;
    if (env_list == NULL)
        return new_node;
    for (env_node_t *tmp = env_list; tmp; tmp = tmp->next)
        if (tmp->next == NULL) {
            tmp->next = new_node;
            return env_list;
        }
    return env_list;
}

env_node_t *drop_node(env_node_t *env_list, env_node_t *node)
{
    if (env_list == NULL)
        return NULL;
    if (env_list == node) {
        env_list = env_list->next;
        free(node);
        return env_list;
    }
    for (env_node_t *tmp = env_list; tmp; tmp = tmp->next)
        if (tmp->next == node) {
            tmp->next = tmp->next->next;
            free(node);
            return env_list;
        }
    return env_list;
}
