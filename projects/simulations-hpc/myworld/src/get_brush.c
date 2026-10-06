/*
** EPITECH PROJECT, 2021
** get_brush.c
** File description:
** brush functions
*/

#include "../includes/my.h"
#include "../includes/my_world.h"

void get_brush_color(Screen *s, Map *map)
{
    if (s->font->brush_tex == 3)
        map->b->brush_color = sfGreen;
    else if (s->font->brush_tex == 4)
        map->b->brush_color = sfRed;
    else
        map->b->brush_color = sfWhite;
}

void get_brush_size(Screen *s, Map *map)
{
    if (s->font->brush_tex > 1) {
        if (sfKeyboard_isKeyPressed(sfKeyAdd))
            map->b->brush_size++;
        else if (sfKeyboard_isKeyPressed(sfKeySubtract))
            map->b->brush_size--;
    }
    if (map->b->brush_size < 0)
        map->b->brush_size = 0;
}

void get_brush(Screen *s, Map *map)
{
    sfCircleShape *circle = sfCircleShape_create();
    double zm = map->camera->zoom;

    get_brush_size(s, map);
    get_brush_color(s, map);
    if (s->font->brush_tex > 1) {
        sfCircleShape_setPosition(circle, (sfVector2f)
        {.x = s->mouse_pos.x - map->b->brush_size * zm,
        .y = s->mouse_pos.y - map->b->brush_size * zm});
        sfCircleShape_setOutlineThickness(circle, 1);
        sfCircleShape_setRadius(circle, map->b->brush_size * zm);
        sfCircleShape_setOutlineColor(circle, map->b->brush_color);
        sfCircleShape_setFillColor(circle, sfTransparent);
        sfRenderWindow_drawCircleShape(s->window, circle, NULL);
        get_brush_points(s, map);
    } else
        get_cluster_points(s, map, s->mouse_pos, map->b->brush_strength);
}

void get_brush_points(Screen *s, Map *map)
{
    double brush = map->b->brush_size
    / (s->Xsize * s->Ysize / pow(50, 2)) * 300;
    double X = map->b->nearest.x - brush / 2;

    get_cluster_points(s, map, s->mouse_pos, 0);
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && get_pythagore(map->cast_map[map->b->nearest.x][map->b->nearest.y],
    (sfVector2f) {s->mouse_pos.x, s->mouse_pos.y}) < 100)
        for (int i = X; i < X + brush; i++)
            sub_get_brush_points(s, map, brush, i);
}
