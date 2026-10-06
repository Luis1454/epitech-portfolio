/*
** EPITECH PROJECT, 2021
** sub.c
** File description:
** sub functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

void switch_get_brush_points(Screen *s, Map *map,
sfVector2f b, sfVector2i v)
{
    double fact = map->Xsize * log10(map->b->brush_size) / 1000;

    switch (s->font->brush_tex) {
        case 2:
            map->test[v.x][v.y].z += log(b.y) * fact;
            break;
        case 3:
            map->test[v.x][v.y].z = (map->b->total_z_values
            / map->b->nb_brush_points + map->test[v.x][v.y].z * 99) / 100;
            break;
        case 4:
            map->test[v.x][v.y].z = map->level;
            break;
    }
}

void sub_get_brush_points(Screen *s, Map *map, double brush, int i)
{
    double Y = map->b->nearest.y - brush / 2;
    double base;

    for (int j = Y; j < Y + brush; j++) {
        base = brush - get_pythagore((sfVector2f)
        {map->b->nearest.x, map->b->nearest.y}, (sfVector2f) {i, j});
        if (check_border(map, (sfVector2f) {i, j}) && base > 1
        && is_in_circle(brush / 2, (sfVector2f)
        {map->b->nearest.x, map->b->nearest.y}, (sfVector2f) {i, j})) {
            switch_get_brush_points(s, map, (sfVector2f)
            {brush, base}, (sfVector2i) {i, j});
            sub_switch_get_brush_points(s, map, (sfVector2f)
            {brush, base}, (sfVector2i) {i, j});
        }
    }
}

void sub_set_point_color(Screen *s, Map *map, sfVector2f p, int size)
{
    if (is_in_circle(size / 2, p, map->v.position)) {
        map->matrix_arr = sfVertexArray_create();
        sfVertexArray_append(map->matrix_arr, map->v);
        sfVertexArray_setPrimitiveType(map->matrix_arr, sfPoints);
        sfRenderWindow_drawVertexArray(s->window, map->matrix_arr, NULL);
        sfVertexArray_destroy(map->matrix_arr);
    }
}

void sub_get_cluster_points(Screen *s, Map *map,
sfVector2i pos, double strength)
{
    if (is_in_circle(5 * map->camera->zoom,
    map->cast_map[map->i][map->j], (sfVector2f) {pos.x, pos.y})) {
        map->b->total_z_values += map->test[map->i][map->j].z;
        if (sfMouse_isButtonPressed(sfMouseLeft)
        || sfMouse_isButtonPressed(sfMouseRight)) {
            get_nearest_point(s, map, (sfVector2f) {map->i, map->j});
            map->b->nearest = (sfVector2i) {map->i, map->j};
        }
        map->b->nb_brush_points++;
    }
}

void sub_get_perlin_noise(Screen *s, Map *map, int size, sfVector2i v)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            map->test[v.x + i * map->i][v.y + j * map->i].z += size * 5;
}
