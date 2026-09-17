/*
** EPITECH PROJECT, 2024
** map_a.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(map_t *map)
{
    unsigned int i = 0;

    for (map_t *tmp = map; tmp; tmp = tmp->next)
        i++;
    return i;
}

bool map_is_empty(map_t *map)
{
    return map == NULL;
}
