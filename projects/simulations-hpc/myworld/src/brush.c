/*
** EPITECH PROJECT, 2021
** brush.c
** File description:
** brush functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

void set_point_color(Screen *s, Map *map)
{
    map->v.color = sfYellow;
    sfVector2f p;
    int size = 5 * map->camera->zoom;

    for (int i = -size / 2; i < size / 2; i++)
        for (int j = -size / 2; j < size / 2; j++) {
            p = map->cast_map[map->b->select.x][map->b->select.y];
            map->v.position.x = p.x + i;
            map->v.position.y = p.y + j;
            sub_set_point_color(s, map, p, size);
        }
}

void get_cluster_points(Screen *s, Map *map, sfVector2i pos, double strength)
{
    int x = s->mouse_pos.x - (int) (map->b->brush_size / 2);
    int y = s->mouse_pos.y - (int) (map->b->brush_size / 2);
    int n = 0;

    map->b->total_z_values = 0;
    map->b->nb_brush_points = 1;
    for (int i = 0; i < map->Xsize; i++) {
        for (int j = 0; j < map->Ysize; j++) {
            map->i = i;
            map->j = j;
            sub_get_cluster_points(s, map, pos, strength);
        }
    }
    sub_get_cluster_point(s, map, pos, strength);
}

int check_border(Map *map, sfVector2f vect)
{
    if (vect.x >= 0 && vect.y >= 0
    && vect.x < map->Xsize && vect.y < map->Ysize)
        return 1;
    return 0;
}

void sub_switch_get_brush_points(Screen *s, Map *map,
sfVector2f b, sfVector2i v)
{
    double fact = map->Xsize * log10(map->b->brush_size) / 1000;

    switch (s->font->brush_tex) {
        case 5:
            map->test[v.x][v.y].z += abs(b.y) * fact / 5;
            break;
        case 6:
            map->test[v.x][v.y].z += sin(b.y) * fact;
            break;
        case 7:
            map->test[v.x][v.y].z += (sin(b.y) - 1 / (b.y + b.x) * 10) * fact;
            break;
        case 8:
            map->test[v.x][v.y].z += tan(b.y) * fact / 10;
            break;
        case 9:
            map->test[v.x][v.y].z += rand() % (int) b.y * fact / 10;
            break;
    }
}

void get_strength(Screen *s, Map *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyRAlt))
        map->b->brush_strength--;
    if (sfKeyboard_isKeyPressed(sfKeyRControl))
        map->b->brush_strength++;
}
