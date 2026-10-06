/*
** EPITECH PROJECT, 2022
** check_map.c
** File description:
** check map functions
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

static int sub_check_map_a_core(Screen *s, char **rdr)
{
    s->nb_tower = 0;
    s->nb_plane = 0;
    s->text = sfText_create();
    if (!s->text)
        return !!my_print_error("Error while creating the text\n");
    for (int i = 0; rdr[i]; i++) {
        s->nb_tower += start_by(rdr[i], "T") && !start_by(rdr[i], "TIME");
        s->nb_plane += start_by(rdr[i], "A")
        && !start_by(rdr[i], "AIRCRAFT_METRIC");
    }
    return init_plane(s) || init_tower(s);
}

int sub_check_map_a(Screen *s, char **rdr)
{
    if (sub_check_map_a_core(s, rdr))
        return 1;
    my_printf("\n%i towers loaded\n", s->nb_tower);
    for (int i = 0, t = 0, j = 0; rdr[i]; i++) {
        for (j = 0; rdr[i][j] && rdr[i][j] != '#'; j++);
        rdr[i][j] = 0;
        if (!start_by(rdr[i], "TIME") && check_tower_format(s,
        rdr[i], t += start_by(rdr[i], "T")))
            return 1;
    }
    return 0;
}

int sub_check_map_b(Screen *s, char **rdr)
{
    if (init_tower_texture(s))
        return 1;
    my_printf("\n%i aircrafts loaded\n", s->nb_plane);
    for (int i = 0, p = 0; rdr[i]; i++) {
        if ((start_by(rdr[i], "AIRCRAFT_METRIC") ? init_plane_metric(s,
        rdr[i]) : 0) || (start_by(rdr[i], "RANGE_METRIC") ?
        init_tower_metric(s, rdr[i]) : 0) || check_time_format(s,
        rdr[i]) || check_plane_format(s, rdr[i],
        p += start_by(rdr[i], "A")))
            return 1;
        free(rdr[i]);
    }
    if (init_plane_texture(s))
        return 1;
    if (rdr)
        free(rdr);
    return 0;
}

int check_map(Screen *s, const char *path)
{
    char *buffer = open_file(path, 1);
    char **rdr;

    if (buffer == NULL)
        return 1;
    if (!buffer[0]) {
        my_print_error("Error: the file \"");
        my_print_error(path);
        my_print_error("\" is empty\n");
    }
    rdr = my_str_to_array(buffer, "\n");
    free(buffer);
    if (!rdr) {
        my_print_error("Error: malloc failed when parsing the file\n");
        return 1;
    }
    if (sub_check_map_a(s, rdr))
        return 1;
    return sub_check_map_b(s, rdr);
}
