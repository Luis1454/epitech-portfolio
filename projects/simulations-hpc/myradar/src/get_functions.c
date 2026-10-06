/*
** EPITECH PROJECT, 2022
** get_functions.c
** File description:
** get methods functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

tower *get_tower_from_icao(Screen *s, char *icao)
{
    for (int i = 0; i < s->nb_tower; i++) {
        if (!my_strcmp(s->tower[i].icao, icao))
            return &(s->tower[i]);
    }
    return NULL;
}

double get_pythagore_3d(vect_3d a, vect_3d b, vect_3d metric)
{
    a.x *= metric.x;
    a.y *= metric.y;
    a.z *= metric.z;

    b.x *= metric.x;
    b.y *= metric.y;
    b.z *= metric.z;
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

void get_plane_collide(Screen *s, int i)
{
    for (int j = 0; j < s->nb_plane; j++)
        if (i != j && is_in_box(s->plane[i].pos,
        s->plane[j].pos, s->collide_metric, s->map_ratio)
        && !is_in_range(s, s->plane[i]) && !is_in_range(s, s->plane[j])
        && !my_strcmp(s->plane[i].status, "FLYING")
        && !my_strcmp(s->plane[j].status, "FLYING")) {
            s->plane[i].status = "CRASHED";
            s->plane[j].status = "CRASHED";
            s->plane[i].speed = 0;
            s->plane[j].speed = 0;
        }
}

double get_min_dist(Screen *s, int i)
{
    double min_dist = -1;
    double dist;

    for (int j = 0; j < s->nb_plane; j++)
        if (i != j && !my_strcmp(s->plane[i].status, "FLYING")
        && !my_strcmp(s->plane[j].status, "FLYING")) {
            dist = get_pythagore_3d(s->plane[i].pos,
            s->plane[j].pos, s->collide_metric);
            min_dist = dist < min_dist || min_dist < 0 ? dist : min_dist;
        }
    return min_dist;
}

double get_rate_to_tower(Screen *s, int i)
{
    double dist = get_pythagore_3d(s->plane[i].pos,
    s->plane[i].flight->arrival, (vect_3d){1, 1, 0});

    return (s->plane[i].pos.z - s->plane[i].flight->arrival.z) / dist;
}
