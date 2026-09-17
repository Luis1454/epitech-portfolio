/*
** EPITECH PROJECT, 2022
** check_plane_a.c
** File description:
** parsing of the planes in the file
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_plane_name(Screen *s, char **line, int i)
{
    char *tmp = my_strdup(line[1]);

    if (!only_contain("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.",
    my_strupcase(tmp))) {
        my_print_error("Error: The aircraft name must only contain ");
        my_print_error("letters, numbers and dashes (");
        my_print_error(line[1]);
        my_print_error(")\n");
        free(tmp);
        return 1;
    }
    s->plane[i].name = my_strdup(line[1]);
    free(tmp);
    return 0;
}

int check_plane_callsign(Screen *s, char **line, int i)
{
    if (!only_contain("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-", line[2])
    || my_strlen(line[2]) < 4 || my_strlen(line[2]) > 7 || line[2][1] != '-') {
        my_print_error("Error: Invalid callsign on an aircraft (");
        my_print_error(line[2]);
        my_print_error(")\n");
        return 1;
    }
    if (callsign_isfree(s, line[2], i)) {
        my_print_error("Error: The callsign is already used by a ");
        my_print_error(s->plane[callsign_isfree(s, line[2], i) - 1].name);
        my_print_error("\n");
        return 1;
    }
    s->plane[i].callsign = my_strdup(line[2]);
    return 0;
}

int check_plane_flight(Screen *s, char **line, int i)
{
    if (flight_handling(s, line))
        return 1;
    s->plane[i].flight->from = my_strdup(line[3]);
    s->plane[i].flight->to = my_strdup(line[4]);
    s->plane[i].flight->departure = get_tower_from_icao(s,
    s->plane[i].flight->from)->pos;
    s->plane[i].flight->arrival = get_tower_from_icao(s,
    s->plane[i].flight->to)->pos;
    s->plane[i].pos = s->plane[i].flight->departure;
    s->plane[i].flight->departure_ts.t = my_getfloat(line[5]);
    return 0;
}

int check_plane_speed(Screen *s, char **line, int i)
{
    if (check_speed(line[7]) || check_speed(line[8]) || check_speed(line[11]))
        return 1;
    s->plane[i].climb_speed = my_getfloat(line[7]);
    s->plane[i].cruise_speed = my_getfloat(line[8]);
    s->plane[i].approach_speed = my_getfloat(line[11]);
    my_printf("Aircraft %s (%s) is flying from %s to %s\n", s->plane[i].name,
    s->plane[i].callsign, s->plane[i].flight->from, s->plane[i].flight->to);
    return 0;
}

int check_plane_altitude(Screen *s, char **line, int i)
{
    if (!only_contain("0123456789.", line[9])) {
        my_print_error("Error: Invalid altitude (");
        my_print_error(line[9]);
        my_print_error(")\nThe altitude must be a positive number\n");
        return 1;
    }
    s->plane[i].cruise_alt = my_getfloat(line[9]);
    if (s->plane[i].cruise_alt <
    get_tower_from_icao(s, s->plane[i].flight->to)->pos.z
    || s->plane[i].cruise_alt <
    get_tower_from_icao(s, s->plane[i].flight->from)->pos.z) {
        my_print_error("Error: Invalid altitude for an aircraft (");
        my_print_error(line[9]);
        my_print_error(" feets)\nThe cruise altitude is lower than the ");
        my_print_error("altitude of the departure or arrival tower\n");
        return 1;
    }
    return 0;
}
