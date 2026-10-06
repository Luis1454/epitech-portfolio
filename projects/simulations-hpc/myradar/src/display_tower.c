/*
** EPITECH PROJECT, 2022
** display_tower.c
** File description:
** display tower functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int display_towers(Screen *s)
{
    double f = 0.8;

    sfSprite_setScale(s->tower_sprite, (sfVector2f){f, f});
    sfSprite_setOrigin(s->tower_sprite, (sfVector2f){24 * f, 21 * f});
    sfSprite_setTexture(s->tower_sprite, s->tower_texture, sfTrue);
    for (int i = 0; i < s->nb_tower; i++) {
        sfSprite_setPosition(s->tower_sprite, (sfVector2f)
        {(s->tower[i].pos.x - s->limit.min.x) / s->map_ratio,
        (s->tower[i].pos.y - s->limit.min.y) / s->map_ratio});
        sfRenderWindow_drawSprite(s->window, s->tower_sprite, NULL);
        display_tower_range(s, s->tower[i]);
        display_tower_state(s, i, (sfVector2f){(s->tower[i].pos.x +
        s->tower[i].range - s->limit.min.x + 10) / s->map_ratio,
        (s->tower[i].pos.y - 31 - s->limit.min.y) / s->map_ratio});
    }
    return 0;
}

static int sub_display_tower_range(Screen *s,
Tower tower, sfCircleShape *circle)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f)
    {(tower.pos.x - s->limit.min.x) / s->map_ratio,
    (tower.pos.y - s->limit.min.y) / s->map_ratio});
    sfRectangleShape_setOrigin(rect,
    (sfVector2f){tower.range / s->map_ratio, 0.5});
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_setRotation(rect, i * 360 / 12);
        sfRectangleShape_setSize(rect, (sfVector2f)
        {tower.range / s->map_ratio * 2, 1});
        sfRectangleShape_setFillColor(rect, (sfColor){0, 255, 0, 127});
        sfRenderWindow_drawRectangleShape(s->window, rect, NULL);
    }
    sfCircleShape_destroy(circle);
    sfRectangleShape_destroy(rect);
    return 0;
}

int display_tower_range(Screen *s, Tower tower)
{
    sfCircleShape *circle = sfCircleShape_create();
    int n = 6;

    if (!circle)
        return !!my_print_error("Error while creating the circle\n");
    sfCircleShape_setFillColor(circle, (sfColor){0, 255, 0, 95 / n});
    sfCircleShape_setOutlineThickness(circle, 1);
    for (int i = 1; i <= n; i++) {
        sfCircleShape_setOutlineColor(circle,
        (sfColor){127, 255, 127, 192 - 72 * i / n});
        sfCircleShape_setPosition(circle, (sfVector2f)
        {(tower.pos.x - s->limit.min.x) / s->map_ratio -
        tower.range / s->map_ratio * i / n,
        (tower.pos.y - s->limit.min.y) / s->map_ratio -
        tower.range / s->map_ratio * i / n});
        sfCircleShape_setRadius(circle, tower.range / s->map_ratio * i / n);
        sfRenderWindow_drawCircleShape(s->window, circle, NULL);
    }
    return sub_display_tower_range(s, tower, circle);
}
