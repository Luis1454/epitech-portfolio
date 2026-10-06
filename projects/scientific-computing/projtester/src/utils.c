/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/tester.h"

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

char *get_last_element(char *str)
{
    int len = my_strlen(str);
    int i = len - 1;

    for (; i >= 0 && str[i] != '/'; i--);
    if (i == len)
        return str;
    return &str[i + 1];
}

void display_tree(list_t *list, int depth)
{
    for (int i = 0; i < depth; i++)
        printf("-----");
    printf("%s\n", list->name);
    if (list->child)
        display_tree(list->child, depth + 1);
    if (list->next)
        display_tree(list->next, depth);
}

char *get_env_path(char **env)
{
    for (int i = 0; env[i]; i++)
        if (!my_strncmp(env[i], "PATH=", 5))
            return my_strdup(env[i] + 5);
    return NULL;
}

int failed_open(char *path)
{
    DIR *dir = opendir(path);

    if (!dir)
        return 1;
    closedir(dir);
    return 0;
}
