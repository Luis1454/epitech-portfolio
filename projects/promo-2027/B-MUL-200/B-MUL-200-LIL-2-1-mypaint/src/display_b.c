/*
** EPITECH PROJECT, 2023
** display_b.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void display_rect(screen_t *s, sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape_setPosition(s->rect, pos);
    sfRectangleShape_setSize(s->rect, size);
    sfRectangleShape_setFillColor(s->rect, color);
    sfRenderWindow_drawRectangleShape(s->window, s->rect, NULL);
    sfRectangleShape_setOutlineThickness(s->rect, 2);
}

void display_color_ramp(screen_t *s,
sfVector2f pos, sfVector2f size, double lightness)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex vertex;
    sfColor color;
    sfVector2f point;

    for (int i = 0; i < size.x; i++) {
        color = get_hue((double)-i / size.x * 2 * PI + 0.5 * PI);
        color.a = 255;
        point = (sfVector2f){pos.x + i, pos.y};
        vertex.position = point;
        vertex.color = mix_color(color,
        lightness < 0 ? sfWhite : sfBlack, ABS(lightness));
        sfVertexArray_append(array, vertex);
    }
    sfRenderWindow_drawVertexArray(s->window, array, NULL);
    sfVertexArray_destroy(array);
}

void display_color_map(screen_t *s, sfVector2f pos, sfVector2f size)
{
    display_rect(s, (sfVector2f){pos.x,
    pos.y}, (sfVector2f){size.x, size.y}, sfBlack);
    for (int j = 0; j < size.y / 2; j++)
        display_color_ramp(s, (sfVector2f){pos.x, pos.y
        + size.y / 2 - j}, size, (double)-(j / (size.y / 2.0)));
    for (int j = 1; j <= size.y / 2; j++)
        display_color_ramp(s, (sfVector2f){pos.x, pos.y
        + size.y / 2 + j}, size, (double)j / (size.y / 2.0));
}

void display_child(screen_t *s, button_t *b, int active)
{
    for (button_t *c = b; c; c = c->next) {
        display_button(s, c, active);
        if (c->child)
            display_child(s, c->child, active);
    }
}

void display_color_picker(screen_t *s)
{
    sfRectangleShape_setOutlineThickness(s->rect, 2);
    display_rect(s, (sfVector2f){s->picker_pos.x +
    s->picker_size.x / 2, s->picker_pos.y + s->picker_size.y / 2},
    (sfVector2f){s->picker_size.x,
    s->picker_size.y}, s->current_brush->bg_color);
    display_rect(s, s->picker_pos, s->picker_size, s->current_brush->color);
}
