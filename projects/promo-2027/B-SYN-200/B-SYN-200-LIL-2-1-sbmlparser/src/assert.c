/*
** EPITECH PROJECT, 2023
** assert.c
** File description:
** asserion functions
*/

#include "../include/my.h"
#include "../include/sbml.h"

int is_in_lst(node_t *lst, char *str)
{
    for (node_t *tmp = lst; tmp; tmp = tmp->next)
        if (!my_strcmp(tmp->name, str))
            return 1;
    return 0;
}

int end_by(char *str, char *pattern)
{
    int i = my_strlen(str) - my_strlen(pattern);

    if (!my_strcmp(&str[i], pattern))
        return 1;
    return 0;
}
