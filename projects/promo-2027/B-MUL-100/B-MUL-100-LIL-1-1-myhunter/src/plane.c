/*
** EPITECH PROJECT, 2022
** plane.c
** File description:
** functions for plane
*/

#include "../include/my.h"
#include "../include/hunter.h"
#include "../include/my_macro_abs.h"

void sub_plane_loop(Screen *s, int i)
{
    if (s->plane[i].pos.y >= s->fixed.y * 0.75)
            s->plane[i].vect.y = -ABS(s->plane[i].vect.y);
    if (s->plane[i].pos.y <= 0)
        s->plane[i].vect.y = ABS(s->plane[i].vect.y);
    if (s->plane[i].pos.x >= s->fixed.x ||
    (is_in_box(s->mouse, s->plane[i].pos, 64 * s->f * (double)s->fixed.x /
    (double)s->size.x, 64 * s->f * (double)s->fixed.y / (double)s->size.y)
    && sfMouse_isButtonPressed(0) && !s->last_click_event)) {
        s->board.score += s->plane[i].pos.x >= s->size.x ? -10 : 1;
        reset_plane(s, i);
        s->last_click_event = TRUE;
    }
}

void plane_loop(Screen *s)
{
    for (int i = 0; i < s->nb_plane; i++) {
        sfSprite_setRotation(s->plane_sprite,
        sin(s->plane[i].vect.y / s->plane[i].vect.x) * 90);
        sfSprite_setScale(s->plane_sprite, (sfVector2f)
        {(double)s->fixed.x / (double)s->size.x * s->f,
        (double)s->fixed.y / (double)s->size.y * s->f});
        sfSprite_setPosition(s->plane_sprite,
        (sfVector2f){s->plane[i].pos.x, s->plane[i].pos.y});
        sub_plane_loop(s, i);
        s->plane[i].pos.x += s->plane[i].vect.x;
        s->plane[i].pos.y += s->plane[i].vect.y;
        sfSprite_setTextureRect(s->plane_sprite,
        (sfIntRect){(int)((s->plane[i].pos.x)
        / 64) * 64 % 5 * 64, s->plane[i].model * 64, 64, 64});
        sfRenderWindow_drawSprite(s->window, s->plane_sprite, NULL);
    }
}
