/*
** EPITECH PROJECT, 2022
** check_time.c
** File description:
** time parsing in the file
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_time_format(Screen *s, char *str)
{
    char **line = my_str_to_array(str, "\t ");

    if (line == NULL || !str || my_strcmp(line[0], "TIME"))
        return 0;
    if (my_arrlen(line) != 3) {
        my_print_error("Error while parsing at the line :\n\"");
        my_print_error(str);
        my_print_error("\"\nWrong number of arguments for TIME\n");
        my_print_error("Expected : TIME <timestamp> <timewarp>\n");
        return 1;
    }
    s->timestamp.t = my_getnbr(line[1]);
    s->timewarp = my_getfloat(line[2]);
    free(line);
    return 0;
}
