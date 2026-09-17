/*
** EPITECH PROJECT, 2021
** my_params_to_list.c
** File description:
** task01
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/mylist.h"

void place_node(char *av, linked_list_t **list)
{
    linked_list_t *node;

    node = malloc(sizeof(*node));
    node->data = av;
    node->next = *list;
    *list = node;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;

    for (int i = 0; i < ac; i++) {
        place_node(av[i], &list);
    }

    return list;
}
