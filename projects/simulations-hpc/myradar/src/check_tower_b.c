/*
** EPITECH PROJECT, 2022
** check_tower_b.c
** File description:
** parsing of the tower file b
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int tower_name_isfree(Screen *s, char *name, int i)
{
    char *tmp = malloc(sizeof(char) * 100);

    for (int j = 0; j < i; j++) {
        if (!my_strcmp(s->tower[j].name, name)) {
            my_print_error("Error: The \"");
            my_print_error(name);
            my_print_error("\" tower name is already used by the ");
            my_print_error(s->tower[j].icao);
            my_print_error(" tower located at (");
            my_print_error(my_itoa(s->tower[j].pos.x, tmp));
            my_print_error(", ");
            my_print_error(my_itoa(s->tower[j].pos.y, tmp));
            my_print_error(", ");
            my_print_error(my_itoa(s->tower[j].pos.z, tmp));
            my_print_error(")\n");
            return j + 1;
        }
    }
    return 0;
}

int sub_check_tower_format(Screen *s, char **line, int id)
{
    int nb = my_arrlen(line);

    if (nb != 9) {
        my_print_error("Error: Wrong number of arguments for a tower (");
        for (int i = 1; i < (3 < nb ? 3 : nb); i++) {
            my_print_error(i - 1 ? " " : "");
            my_print_error(line[i]);
        }
        my_print_error(")\n");
        my_print_error("Expected 9, got ");
        my_putnbr_error(nb);
        my_print_error("\n");
        return 1;
    }
    return check_tower_info(s, line, id);
}

int check_tower_format(Screen *s, char *str, int t)
{
    char **line = my_str_to_array(str, "\t ");

    if (line == NULL)
        return 0;
    if (!my_strcmp(line[0], "T"))
        return sub_check_tower_format(s, line, t - 1);
    free(line);
    return 0;
}

int check_tower_info(Screen *s, char **line, int i)
{
    if (check_tower_name(s, line, i) || check_tower_icao(s, line, i)
    || check_tower_coord(s, line, i) || check_tower_range(s, line, i)
    || check_tower_capacity(s, line, i))
        return 1;
    update_limits(s, (sfVector2f){s->tower[i].pos.x, s->tower[i].pos.y});
    update_limits(s, (sfVector2f){s->tower[i].pos.x + s->tower[i].range,
    s->tower[i].pos.y + s->tower[i].range});
    update_limits(s, (sfVector2f){s->tower[i].pos.x - s->tower[i].range,
    s->tower[i].pos.y - s->tower[i].range});
    return 0;
}

int display_tower_state(Screen *s, int i, sfVector2f pos)
{
    char *tmp_a = malloc(sizeof(char) * 20);
    char *tmp_b = malloc(sizeof(char) * 20);

    tmp_a = my_memset(tmp_a, 0, 20);
    tmp_b = my_memset(tmp_b, 0, 20);
    my_itoa(s->tower[i].nb_taxiing, tmp_a);
    tmp_a = my_strcat(tmp_a, "/");
    tmp_a = my_strcat(tmp_a, my_itoa(s->tower[i].capacity, tmp_b));
    add_text(s, s->text, s->tower[i].name, pos);
    add_text(s, s->text, tmp_a, (sfVector2f){pos.x, pos.y + 30});
    my_itoa(s->tower[i].range, tmp_a);
    my_strcat(tmp_a, " nm");
    add_text(s, s->text, tmp_a, (sfVector2f){pos.x, pos.y + 15});
    free(tmp_a);
    free(tmp_b);
    return 0;
}
