/*
** EPITECH PROJECT, 2022
** assert_a.c
** File description:
** assertion functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int tower_exists(Screen *s, char *icao)
{
    for (int i = 0; i < s->nb_tower; i++) {
        if (!my_strcmp(s->tower[i].icao, icao))
            return 1;
    }
    return 0;
}

int callsign_isfree(Screen *s, char *callsign, int i)
{
    for (int j = 0; j < i; j++) {
        if (!my_strcmp(s->plane[j].callsign, callsign))
            return j + 1;
    }
    return 0;
}

int check_speed(const char *str)
{
    if (!only_contain("0123456789.", str)) {
        my_print_error("Error: Invalid speed (");
        my_print_error(str);
        my_print_error(")\nThe speed must be a positive number\n");
        return 1;
    }
    return 0;
}

int is_in_range(Screen *s, Plane plane)
{
    for (int i = 0; i < s->nb_tower; i++)
        if (get_pythagore_3d(s->tower[i].pos,
        plane.pos, s->range_metric) <= s->tower[i].range)
            return 1;
    return 0;
}

int is_plane_at_dest(Plane plane, vect_3d size)
{
    vect_3d pos = plane.pos;
    vect_3d dest = plane.flight->arrival;

    return pos.x > dest.x - size.x && pos.x < dest.x + size.x
    && pos.y > dest.y - size.y && pos.y < dest.y + size.y;
}
