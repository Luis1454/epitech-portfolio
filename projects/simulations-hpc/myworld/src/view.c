/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** init functions
*/

#include "../includes/my.h"
#include "../includes/my_world.h"

void get_perlin_noise(Screen *s, Map *map, int size)
{
    sfVector2i v;

    for (int i = 0; i < map->i; i++)
        for (int j = 0; j < map->i; j++) {
            v.x = i;
            v.y = j;
            map->test[rand() % (int) map->Xsize][rand()
            % (int) map->Ysize].z += size / 2;
        }
    map->i *= 2;
    if (size > 1)
        get_perlin_noise(s, map, size / 2);
}

void reset_evelation(Screen *s, Map *map)
{
    for (int i = 0; i < map->Xsize; i++)
        for (int j = 0; j < map->Ysize; j++)
            map->test[i][j].z = 0;
}

sfVector2f sub_get_iso(Map *map, sfVector3f *v, int state)
{
    double Xtranslated = v->x - 10 * map->Xsize / 2;
    double Ytranslated = v->y - 10 * map->Ysize / 2;

    v->x = Xtranslated * cos(map->rot) + Ytranslated * -sin(map->rot);
    v->y = Xtranslated * sin(map->rot) + Ytranslated * cos(map->rot);
    if (state) {
        v->x *= map->camera->zoom;
        v->y *= map->camera->zoom;
        v->z *= map->camera->zoom;
    }
    v->x += 10 * map->Xsize / 2;
    v->y += 10 * map->Ysize / 2;

    map->abs_rot.x = (int) (map->abs_rot.x + map->rot) % 360;
    map->abs_rot.y = (int) (map->abs_rot.y + map->rot) % 360;
    map->abs_rot.z = (int) (map->abs_rot.z + map->rot) % 360;
}

sfVector2f get_iso(Screen *s, Map *map, sfVector3f *v, int state)
{
    sfVector2f vect;
    double A = map->camera->X / 50;
    double B = map->camera->Y / 50;

    sub_get_iso(map, v, state);
    vect.x = (v->x * (50 + A) / map->Ysize - v->y * (50 + A)
    / map->Ysize - map->Ysize) + map->Ysize;
    vect.y = (v->x + v->y - map->Ysize * 10) * sin(B) / 2 - v->z + map->Ysize;
    vect.x += (int) (s->Xsize / 2);
    vect.y += (int) (s->Ysize / 2);
    v->x -= 10 * map->Xsize / 2;
    v->y -= 10 * map->Ysize / 2;
    if (state)
        reset_axis(map, v);
    v->x += 10 * map->Xsize / 2;
    v->y += 10 * map->Ysize / 2;

    return vect;
}

int draw_map(Screen *s, Map *map)
{
    void get_perlin_noise(Screen *s, Map *map, int size);
    for (int i = 0; i < map->Xsize - 1; i++) {
        for (int j = 0; j < map->Ysize - 1; j++) {
            vertex_x(s, map, i, j);
            vertex_y(s, map, i, j);
        }
        vertex_x(s, map, map->Ysize - 1, i);
    }
    for (int i = 0; i < map->Xsize - 1; i++)
        vertex_y(s, map, i, map->Xsize - 1);
    return 0;
}
