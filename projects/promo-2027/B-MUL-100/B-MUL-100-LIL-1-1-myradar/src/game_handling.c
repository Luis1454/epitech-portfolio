/*
** EPITECH PROJECT, 2022
** game_handling.c
** File description:
** functions for the game
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int init_window(Screen *s, sfVideoMode mode)
{
    s->window = sfRenderWindow_create(mode, "My_Radar", sfClose, NULL);
    if (!s->window) {
        my_print_error("Error while creating the window\n");
        return 1;
    }
    s->font = sfFont_createFromFile("fonts/nasa.otf");
    if (!s->font) {
        my_print_error("Error while loading the font\n");
        return 1;
    }
    return 0;
}

void display_grid(Screen *s)
{
    int margin = 50;
    int pos = margin;
    sfColor color = {0, 255, 0, 92};
    sfRectangleShape *lines = sfRectangleShape_create();
    sfRectangleShape_setFillColor(lines, color);
    for (int i = 0; i < s->size.x / margin; i++) {
        if (pos < s->size.y) {
            sfRectangleShape_setPosition(lines, (sfVector2f){0, pos});
            sfRectangleShape_setSize(lines, (sfVector2f){s->size.x, 1});
            sfRenderWindow_drawRectangleShape(s->window, lines, NULL);
        }
        sfRectangleShape_setPosition(lines, (sfVector2f){pos, 0});
        sfRectangleShape_setSize(lines, (sfVector2f){1, s->size.y});
        sfRenderWindow_drawRectangleShape(s->window, lines, NULL);
        pos += margin;
    }
    sfRectangleShape_destroy(lines);
}

void add_text(Screen *s, sfText *t, char *str, sfVector2f pos)
{
    sfText_setString(t, str);
    sfText_setPosition(t, pos);
    sfRenderWindow_drawText(s->window, t, NULL);
}

int flight_handling(Screen *s, char **line)
{
    if (!tower_exists(s, line[3]) || !tower_exists(s, line[4])) {
        my_print_error("Error: A tower doesn't exist (");
        my_print_error(tower_exists(s, line[3]) ? line[4] : line[3]);
        return !!my_print_error(")\n");
    } else if (!only_contain("0123456789.", line[5])) {
        my_print_error("Error: Invalid flight number (");
        my_print_error(line[5]);
        my_print_error(")\nThe flight number must be a positive number\n");
        return 1;
    }
    if (!my_strcmp(line[3], line[4])) {
        my_print_error("Error: The departure and arrival are the same (");
        my_print_error(line[3]);
        return !!my_print_error(")\n");
    }
    return 0;
}
