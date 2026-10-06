/*
** EPITECH PROJECT, 2022
** check_plane_b.c
** File description:
** parsing of the planes in the file
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_plane_rate(Screen *s, char **line, int i)
{
    if (!only_contain("0123456789.", line[6])) {
        my_print_error("Error: Invalid climb rate (");
        my_print_error(line[6]);
        my_print_error(")\nThe climb rate must be a positive number\n");
        return 1;
    }
    if (!only_contain("0123456789.", line[10])) {
        my_print_error("Error: Invalid decent rate (");
        my_print_error(line[10]);
        my_print_error(")\nThe decent rate must be a positive number\n");
        return 1;
    }
    s->plane[i].climb_rate = my_getfloat(line[6]);
    s->plane[i].approach_rate = my_getfloat(line[10]);
    return 0;
}

int check_plane_info(Screen *s, char **line, int i)
{
    if (check_plane_name(s, line, i) || check_plane_callsign(s, line, i)
    || check_plane_flight(s, line, i) || check_plane_speed(s, line, i)
    || check_plane_altitude(s, line, i) || check_plane_rate(s, line, i))
        return 1;
    s->plane[i].path = malloc(sizeof(vect_3d) * PATH_HIST_LEN);
    s->plane[i].speed = 10;
    if (s->plane[i].path == NULL)
        return 1;
    s->plane[i].status = my_strdup_up("PARKED", 15);
    s->plane[i].flight->step = my_strdup_up("CLIMB", 10);
    s->plane[i].waiting = 1;
    init_path_history(s, i);
    return 0;
}

static int sub_check_plane_format(Screen *s, char **line, int id)
{
    int nb = my_arrlen(line);

    if (nb != 15) {
        my_print_error("Error: Wrong number of arguments for an aircraft (");
        for (int i = 1; i < (3 < nb ? 3 : nb); i++) {
            my_print_error(i - 1 ? " " : "");
            my_print_error(line[i]);
        }
        my_print_error(")\n");
        my_print_error("Expected 15, got ");
        my_putnbr_error(nb);
        my_print_error("\n");
        return 1;
    }
    return check_plane_info(s, line, id);
}

int check_plane_format(Screen *s, char *str, int p)
{
    char **line = my_str_to_array(str, "\t ");

    if (line == NULL)
        return 0;
    if (!my_strcmp(line[0], "A"))
        return sub_check_plane_format(s, line, p - 1);
    free(line);
    return 0;
}
