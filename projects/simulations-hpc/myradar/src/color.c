/*
** EPITECH PROJECT, 2022
** color.c
** File description:
** color functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

sfColor get_hue(double n)
{
    sfColor hue = {0, 0, 0, 255};

    hue.r = ABS((int)(127 * (1 + sin(n))));
    hue.g = ABS((int)(127 * (1 + sin(n + 2))));
    hue.b = ABS((int)(127 * (1 + sin(n + 4))));

    return hue;
}

sfColor set_color_by_distance(Screen *s, int i)
{
    double dist = get_min_dist(s, i);
    double ratio = dist / 250;
    sfColor safe = sfGreen;
    sfColor danger = sfRed;
    sfColor color;

    color = mix_color(safe, danger, ratio < 0 ? 0 : 1 - ratio);
    ratio = ratio < 0 ? 0 : 1 - ratio;
    ratio = ratio > 1 ? 1 : ratio;
    ratio = ratio < 0 ? 0 : ratio;
    sfRectangleShape_setOutlineThickness(s->plane_rect, is_in_range(s,
    s->plane[i]) ? 2 : ratio > 0.75 ? 3 : ratio > 0.5 ? 2 : 1);
    color = ratio > 0.85 ? sfYellow : color;
    return is_in_range(s, s->plane[i]) ?
    (sfColor){63, 167, 255, 255} : color;
}

sfColor mix_color(sfColor a, sfColor b, double ratio)
{
    sfColor color;

    ratio = ratio > 1 ? 1 : ratio;
    ratio = ratio < 0 ? 0 : ratio;

    color.r = a.r * (1 - ratio) + b.r * ratio;
    color.g = a.g * (1 - ratio) + b.g * ratio;
    color.b = a.b * (1 - ratio) + b.b * ratio;
    color.a = a.a * (1 - ratio) + b.a * ratio;
    return color;
}

void update_limits(Screen *s, sfVector2f pos)
{
    if (pos.x < s->limit.min.x)
        s->limit.min.x = pos.x;
    if (pos.x > s->limit.max.x)
        s->limit.max.x = pos.x;
    if (pos.y < s->limit.min.y)
        s->limit.min.y = pos.y;
    if (pos.y > s->limit.max.y)
        s->limit.max.y = pos.y;
}

int get_planes_in_sky(Screen *s)
{
    int nb = 0;

    for (int i = 0; i < s->nb_plane; i++)
        if (!my_strcmp(s->plane[i].status, "FLYING"))
            nb++;
    return nb / s->nb_plane < 0.1 ? s->nb_plane : nb;
}
