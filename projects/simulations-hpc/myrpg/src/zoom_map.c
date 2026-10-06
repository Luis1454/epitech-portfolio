/*
** EPITECH PROJECT, 2022
** zoom_map.c
** File description:
** zoom handling
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void zoom_map(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd))
        map->rescale += map->zoom_speed;
    if (sfKeyboard_isKeyPressed(sfKeySubtract))
        map->rescale -= map->zoom_speed;
    map->rescale = map->rescale > MAX_ZOOM ? MAX_ZOOM : map->rescale;
    map->rescale = map->rescale < MIN_ZOOM ? MIN_ZOOM : map->rescale;
}
