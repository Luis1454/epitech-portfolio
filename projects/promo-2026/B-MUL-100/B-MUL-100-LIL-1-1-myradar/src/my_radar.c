/*
** EPITECH PROJECT, 2021
** my_radar.c
** File description:
** core file
*/

#include <stdlib.h>
#include "../includes/include.h"
#include "../includes/my.h"

int is_in_circle(int len, int size, Plane p, Tower t[len])
{
    int d;
    int a;
    int b;

    for (int i = 0; i < len; i++) {
        a = p.X + 10 - t[i].X;
        b = p.Y + 10 - t[i].Y;
        if (a < 0)
            a = -a;
        if (b < 0)
            b = -b;
        if (pwr(a, 2) + pwr(b, 2) < pwr(t[i].radius * size / 50000, 2))
            return 1;
    }
    return 0;
}

void sub_my_radar_B(Screen *s, Stat *st, Plane planes[], Tower towers[])
{
    while (sfRenderWindow_isOpen(s->window)) {
        get_events(s->window, s->event, s->sprite);
        for (int i = 0; i < st->nbPlanes; i++) {
            st->i = i;
            plane_loop_A(s, st, planes, towers);
            plane_loop_B(s, st, planes, towers);
        }
        tower_loop(s, st, towers);
    }
}

int sub_my_radar_A(Screen *s, Stat *st, Plane planes[], Tower towers[])
{
    st->nbPlanes = get_P_len(st->nbPlanes, planes);
    st->nbTowers = get_T_len(st->nbTowers, towers);
    get_T_plate(st->nbTowers, towers);
    get_P_name(st->nbPlanes, planes);
    if (s->window == NULL)
        return 84;
    if (s->texture != NULL) {
        sfRenderWindow_setFramerateLimit(s->window, s->shutter);
        sfSprite_setTexture(s->sprite, s->texture, sfTrue);
        sfSprite_setTexture(s->traceMap, s->trace, sfTrue);
        sub_my_radar_B(s, st, planes, towers);
        sfTexture_destroy(s->texture);
    }
    sfRenderWindow_destroy(s->window);
    sfSprite_destroy(s->traceMap);
    sfSprite_destroy(s->sprite);
    sfSprite_destroy(s->pln_sprite);
    sfSprite_destroy(s->twr_sprite);
    free(s->pixels);
    return 0;
}

int my_radar(Stat *st, Plane planes[], Tower towers[])
{
    Screen *s = malloc(sizeof(Screen));
    init_A(s);
    init_B(s);
    sfRectangleShape_setSize(s->rect, (sfVector2f) {20, 20});
    sfText_setFont(s->text, s->font);
    sfCircleShape_setOutlineColor(s->circle, sfGreen);
    sfRectangleShape_setFillColor(s->rect, sfTransparent);
    sfCircleShape_setFillColor(s->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(s->circle, 1);
    s->window = sfRenderWindow_create(s->mode, "my_radar",
    sfResize | sfClose, NULL);

    if (s->pln_texture != NULL)
        sfSprite_setTexture(s->pln_sprite, s->pln_texture, sfTrue);
    if (s->twr_texture != NULL)
        sfSprite_setTexture(s->twr_sprite, s->twr_texture, sfTrue);
    return sub_my_radar_A(s, st, planes, towers);
}
