/*
** EPITECH PROJECT, 2023
** display_d.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void display_grid(screen_t *s, sfColor color, int margin)
{
    int pos = margin;
    sfRectangleShape *lines = sfRectangleShape_create();

    sfRectangleShape_setFillColor(lines, color);
    for (int i = 0; i < s->draw_area.b.x / margin; i++) {
        if (pos < s->draw_area.b.y) {
            sfRectangleShape_setPosition(lines, (sfVector2f)
            {s->draw_area.a.x, s->draw_area.a.y + pos});
            sfRectangleShape_setSize(lines, (sfVector2f){s->draw_area.b.x, 1});
            sfRenderWindow_drawRectangleShape(s->window, lines, NULL);
        }
        sfRectangleShape_setPosition(lines, (sfVector2f)
        {s->draw_area.a.x + pos, s->draw_area.a.y});
        sfRectangleShape_setSize(lines, (sfVector2f){1, s->draw_area.b.y});
        sfRenderWindow_drawRectangleShape(s->window, lines, NULL);
        pos += margin;
    }
    sfRectangleShape_destroy(lines);
}
