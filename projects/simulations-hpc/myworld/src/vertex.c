/*
** EPITECH PROJECT, 2021
** vertex.c
** File description:
** utils functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

int coord(Screen *s, Map *map)
{
    for (int i = 0; i < map->Ysize; i++)
        for (int j = 0; j < map->Xsize; j++) {
            map->test[i][j].y = (j * 10);
            map->test[i][j].x = (i * 10);
        }
}

void get_2d_map(Screen *s, Map *map)
{
    for (int i = 0; i < map->Xsize; i++)
        for (int j = 0; j < map->Ysize; j++)
            map->cast_map[i][j] = get_iso(s, map, &map->test[i][j], 1);
}

void create_line(Map *map, sfVector2f p1, sfVector2f p2, sfVector3f vect3d)
{
    sfVertex A = {.position = p1, .color = sfColor_fromRGB(0, 0, 100)};
    sfVertex B = {.position = p2, .color = sfColor_fromRGB(0, 100, 0)};

    map->matrix_arr = sfVertexArray_create();
    sfVertexArray_append(map->matrix_arr, A);
    sfVertexArray_append(map->matrix_arr, B);
    sfVertexArray_setPrimitiveType(map->matrix_arr, sfLineStrip);
}

void vertex_x(Screen *s, Map *map, int i, int j)
{
    create_line(map, map->cast_map[i][j],
    map->cast_map[i][j + 1],map->test[i][j]);
    sfRenderWindow_drawVertexArray(s->window, map->matrix_arr, NULL);
    sfVertexArray_destroy(map->matrix_arr);
}

void vertex_y(Screen *s, Map *map, int i, int j)
{
    create_line(map, map->cast_map[i][j],
    map->cast_map[i + 1][j], map->test[i][j]);
    sfRenderWindow_drawVertexArray(s->window, map->matrix_arr, NULL);
    sfVertexArray_destroy(map->matrix_arr);
}
