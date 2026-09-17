/*
** EPITECH PROJECT, 2022
** init_tower.c
** File description:
** init tower functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int init_tower_texture(Screen *s)
{
    s->tower_texture = sfTexture_createFromFile("texture/tower.png", NULL);
    s->tower_sprite = sfSprite_create();
    if (!s->tower_texture || !s->tower_sprite) {
        my_print_error("Error while loading the texture\n");
        return 1;
    }
    return 0;
}

int init_tower_metric(Screen *s, char *str)
{
    char **arr = my_str_to_array(str, "\n\t ");

    if (check_metric(arr, str, "RANGE_METRIC"))
        return 1;
    s->range_metric = (vect_3d){my_getfloat(arr[1]),
    my_getfloat(arr[2]), my_getfloat(arr[3])};
    return 0;
}

int init_tower(Screen *s)
{
    if (!s->nb_tower) {
        my_print_error("Error: no tower found\n");
        return 1;
    }
    s->tower = malloc(sizeof(Tower) * s->nb_tower);
    if (!s->tower) {
        my_print_error("Error: malloc failed when allocating towers\n");
        return 1;
    }
    return 0;
}
