/*
** EPITECH PROJECT, 2022
** check_tower_a.c
** File description:
** parsing of the tower file a
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_tower_name(Screen *s, char **line, int i)
{
    char *tmp = my_strdup(line[1]);

    if (!only_contain("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.",
    my_strupcase(tmp))) {
        my_print_error("Error: The tower name must only contain ");
        my_print_error("letters, numbers and dashes (");
        my_print_error(line[1]);
        my_print_error(")\n");
        free(tmp);
        return 1;
    }
    s->tower[i].name = my_strdup(line[1]);
    free(tmp);
    return tower_name_isfree(s, line[1], i);
}

int check_tower_icao(Screen *s, char **line, int i)
{
    if (!only_contain("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-", line[2])
    || my_strlen(line[2]) != 4) {
        my_print_error("Error: Invalid ICAO code on a tower (");
        my_print_error(line[1]);
        my_print_error(")\n");
        return 1;
    }
    s->tower[i].icao = my_strdup(line[2]);
    my_printf("ICAO code of %s is %s\n", line[1], line[2]);
    return 0;
}

int check_tower_coord(Screen *s, char **line, int i)
{
    for (int j = 3; j < 6; j++) {
        if (!only_contain("0123456789.", line[j])) {
            my_print_error("Error: Invalid coordinates on a tower (");
            my_print_error(line[1]);
            my_print_error(")\n");
            return 1;
        }
    }
    s->tower[i].pos.x = my_getfloat(line[3]);
    s->tower[i].pos.y = my_getfloat(line[4]);
    s->tower[i].pos.z = my_getfloat(line[5]);

    return 0;
}

int check_tower_range(Screen *s, char **line, int i)
{
    if (!only_contain("0123456789.", line[6])) {
        my_print_error("Error: Invalid range on a tower (");
        my_print_error(line[1]);
        my_print_error(")\n");
        if (my_getfloat(line[6]) < 0)
            my_print_error("The range must be a positive integer\n");
        else
            my_print_error("The range must only contain numbers\n");
        return 1;
    }
    s->tower[i].range = my_getfloat(line[6]);
    return 0;
}

int check_tower_capacity(Screen *s, char **line, int i)
{
    if (!only_contain("0123456789", line[7])) {
        my_print_error("Error: Invalid capacity on a tower (");
        my_print_error(line[1]);
        my_print_error(")\n");
        if (my_getnbr(line[7]) < 0)
            my_print_error("The capacity must be a positive integer\n");
        else
            my_print_error("The capacity must only contain numbers\n");
        return 1;
    }
    s->tower[i].capacity = my_getnbr(line[7]);
    s->tower[i].nb_taxiing = 0;
    return 0;
}
