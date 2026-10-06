/*
** EPITECH PROJECT, 2022
** init_pathmask.c
** File description:
** pathmask init functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void reset_path_mask(Screen *s)
{
    for (int i = 0; i < (s->size.x * s->size.y); i++)
        s->path_mask_index[i] = sfTransparent;
}

void init_path_history(Screen *s, int i)
{
    for (int n = 0; n < PATH_HIST_LEN; n++)
        s->plane[i].path[n] = s->plane[i].pos;
}

static int sub_init_pathmask(Screen *s)
{
    s->path_sprite = sfSprite_create();
    s->path_texture = sfTexture_create(s->size.x, s->size.y);
    sfSprite_setTexture(s->path_sprite, s->path_texture, sfTrue);
    s->path_mask = malloc(sizeof(Path) * s->size.x * s->size.y);
    s->path_mask_index = malloc(sizeof(sfColor) * s->size.x * s->size.y);
    if (!s->path_mask_index || !s->path_mask) {
        my_print_error("Error while allocating memory for the path mask\n");
        return 1;
    }
    return 0;
}

int init_pathmask(Screen *s)
{
    if (sub_init_pathmask(s))
        return 1;
    if (!s->path_mask || !s->path_sprite || !s->path_texture) {
        my_print_error("Error: malloc failed when allocating the pathmask\n");
        return 1;
    }
    for (int i = 0; i < s->size.x * s->size.y; i++) {
        s->path_mask[i].plane = NULL;
        s->path_mask[i].altitude = 0;
        s->path_mask[i].speed = 0;
        s->path_mask[i].heading = 0;
        s->path_mask[i].n = 0;
    }
    return 0;
}
