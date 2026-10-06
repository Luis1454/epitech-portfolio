/*
** EPITECH PROJECT, 2021
** get.c
** File description:
** brush functions
*/

#include "../includes/my.h"
#include "../includes/my_world.h"

void get_cursor_actions(Screen *s, Map *map, double strength)
{
    if (!s->font->brush_tex)
        map->test[map->b->nearest.x][map->b->nearest.y].z += strength;
    else if (s->font->brush_tex == 1)
        map->b->select = map->b->nearest;
}

void get_nearest_point(Screen *s, Map *map, sfVector2f pos)
{
    if (get_pythagore(pos, (sfVector2f) {map->b->nearest.x,
    map->b->nearest.y}) < map->b->dist) {
        map->b->nearest = (sfVector2i) {.x = pos.x, .y = pos.y};
        map->b->dist = get_pythagore(pos, (sfVector2f)
        {map->b->nearest.x, map->b->nearest.y});
    }
}

void sub_get_cluster_point(Screen *s, Map *map,
sfVector2i pos, double strength)
{
    set_point_color(s, map);
    if (get_pythagore(map->cast_map[map->b->nearest.x][map->b->nearest.y],
    (sfVector2f) {s->mouse_pos.x, s->mouse_pos.y}) < 100
    && map->b->brush_state) {
        map->b->brush_state = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            get_cursor_actions(s, map, strength);
        if (sfMouse_isButtonPressed(sfMouseRight))
            get_cursor_actions(s, map, -strength);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft)
    && !sfMouse_isButtonPressed(sfMouseRight))
        map->b->brush_state = 1;
}