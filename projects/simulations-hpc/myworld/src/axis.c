/*
** EPITECH PROJECT, 2021
** axis.c
** File description:
** viewport 3D axis functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

void place_axis(Screen *s, Map *map, sfVector3f *vect, sfVertex *v)
{
    v->position.x += s->Xsize / 2 - 90;
    v->position.y -= s->Ysize * 3 / 5 - 105;
}

void get_axis(Screen *s, Map *map, sfVector3f *vect, sfColor c)
{
    sfVector3f v1 = {map->Xsize / 2 * 10, map->Ysize / 2 * 10, 0};
    double tmp = map->rot;
    sfVertex A;
    sfVertex B;

    map->abs_rot = map->abs_rot;
    A = (sfVertex) {.position = get_iso(s, map, &v1, 0), .color = c};
    B = (sfVertex) {.position = get_iso(s, map, vect, 0), .color = c};
    map->rot = tmp;
    map->matrix_arr = sfVertexArray_create();
    place_axis(s, map, vect, &A);
    place_axis(s, map, vect, &B);
    sfVertexArray_append(map->matrix_arr, A);
    sfVertexArray_append(map->matrix_arr, B);
    sfVertexArray_setPrimitiveType(map->matrix_arr, sfLineStrip);
    sfRenderWindow_drawVertexArray(s->window, map->matrix_arr, NULL);
    sfVertexArray_destroy(map->matrix_arr);
}

void build_axis(Screen *s, Map *map)
{
    get_axis(s, map, &map->X_pos, sfRed);
    get_axis(s, map, &map->Y_pos, sfGreen);
    get_axis(s, map, &map->Z_pos, sfBlue);
}
