/*
** EPITECH PROJECT, 2022
** pathmask.c
** File description:
** pathmask handling functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void trace_path(Screen *s)
{
    for (int n = 0; n < s->nb_plane; n++)
        if (!my_strcmp(s->plane[n].status, "FLYING"))
            sub_trace_path(s, n);
}

void display_pathmask(Screen *s)
{
    trace_path(s);
    sfTexture_updateFromPixels(s->path_texture,
    (sfUint8 *)s->path_mask_index, s->size.x, s->size.y, 0, 0);
    sfRenderWindow_drawSprite(s->window, s->path_sprite, NULL);
}

void update_path(Screen *s, int n)
{
    for (int i = 0; i < PATH_HIST_LEN - 1; i++)
        s->plane[n].path[i] = s->plane[n].path[i + 1];
    s->plane[n].path[PATH_HIST_LEN - 1] = s->plane[n].pos;
}

void sub_trace_path(Screen *s, int n)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < PATH_HIST_LEN; i++) {
        x = (s->plane[n].path[i].x - s->limit.min.x) / s->map_ratio;
        y = (s->plane[n].path[i].y - s->limit.min.y) / s->map_ratio;
        if (x >= 0 && x < s->size.x && y >= 0 && y < s->size.y)
            s->path_mask_index[y * s->size.x + x]
            = get_hue(4 + s->plane[n].path[i].z / ((5 / 3) * 10000));
    }
}
