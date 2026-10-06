/*
** EPITECH PROJECT, 2022
** color.c
** File description:
** color functions
*/

#include "../include/my.h"
#include "../include/paint.h"
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

sfColor set_color_by_distance(double distance, double max_distance)
{
    sfColor color = {0, 0, 0, 255};

    if (distance == -1)
        return color;
    color = get_hue(distance / max_distance * 2 * PI);
    return color;
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

sfColor add_color(sfColor a, sfColor b, double ratio)
{
    sfColor color;

    ratio = ratio > 1 ? 1 : ratio;
    ratio = ratio < 0 ? 0 : ratio;

    color.r = a.r + b.r * ratio;
    color.g = a.g + b.g * ratio;
    color.b = a.b + b.b * ratio;
    color.a = a.a + b.a * ratio;

    return color;
}

sfColor get_color_from_map(sfVector2f pos, sfVector2f size, sfVector2f mouse)
{
    sfColor color = {0, 0, 0, 255};
    double ratio = 0;
    double lightness = 0;

    if (!is_in_box((frame_t){pos, size}, mouse))
        return color;
    ratio = (double)(mouse.x - pos.x) / size.x;
    lightness = (double)(mouse.y - pos.y - size.y / 2) / (size.y / 2);
    color = get_hue(-ratio * 2 * PI + 0.5 * PI);
    color = mix_color(color, lightness < 0 ? sfWhite : sfBlack, ABS(lightness));
    return color;
}
