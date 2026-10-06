/*
** EPITECH PROJECT, 2022
** assert_b.c
** File description:
** assertion functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int is_in_box(vect_3d a, vect_3d b, vect_3d metric, double map_ratio)
{
    vect_3d size = (vect_3d){20, 20, 20};

    a.x *= metric.x;
    a.y *= metric.y;
    a.z *= metric.z;

    b.x *= metric.x;
    b.y *= metric.y;
    b.z *= metric.z;

    size.x *= map_ratio;
    size.y *= map_ratio;
    size.z *= map_ratio;

    return a.x >= b.x - size.x && a.x <= b.x + size.x &&
    a.y >= b.y - size.y && a.y <= b.y + size.y &&
    a.z >= b.z - size.z && a.z <= b.z + size.z;
}

int is_plane_at_start(Plane plane, vect_3d size)
{
    vect_3d pos = plane.pos;
    vect_3d start = plane.flight->departure;

    return pos.x > start.x - size.x && pos.x < start.x + size.x
    && pos.y > start.y - size.y && pos.y < start.y + size.y;
}

int no_man_sky(Screen *s)
{
    for (int i = 0; i < s->nb_plane; i++)
        if ((is_plane_at_start(s->plane[i], (vect_3d){2, 2, 2})
        && !my_strcmp(s->plane[i].status, "PARKED"))
        || !my_strcmp(s->plane[i].status, "FLYING")
        || !my_strcmp(s->plane[i].status, "TAXIING"))
            return 0;
    return 1;
}

int start_by(char *str, char *start)
{
    int i = 0;

    if (!str || !start)
        return 0;
    for (; str[i] && start[i] && str[i] == start[i]; i++);
    return i == my_strlen(start);
}

int has_priority(Screen *s, int i)
{
    Tower *t = get_tower_from_icao(s, s->plane[i].flight->to);
    int priority = -1;

    if (my_strcmp(s->plane[i].status, "FLYING"))
        return 0;
    for (int j = 0; j < s->nb_plane; j++)
        if (i != j && !my_strcmp(s->plane[j].status, "FLYING")
        && !my_strcmp(s->plane[j].flight->to, s->plane[i].flight->to)
        && get_pythagore_3d(s->plane[i].pos, t->pos, (vect_3d){1, 1, 0})
        / s->plane[i].speed * s->plane[i].pos.z >
        get_pythagore_3d(s->plane[j].pos, t->pos, (vect_3d){1, 1, 0})
        / s->plane[j].speed * s->plane[j].pos.z)
            priority = j;
    return priority == -1 || i == priority;
}
