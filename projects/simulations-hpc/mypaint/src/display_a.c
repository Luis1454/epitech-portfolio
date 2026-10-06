/*
** EPITECH PROJECT, 2023
** display_a.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void display_slider(screen_t *s, slider_t *slider, int is_float)
{
    char *str;
    double ratio = (double)slider->value / (double)(slider->max - slider->min);

    display_rect(s, slider->pos, slider->size, sfWhite);
    for (int i = 0; i < slider->size.x * ratio; i++) {
        sfRectangleShape_setOutlineThickness(s->rect, 0);
        display_rect(s, (sfVector2f){slider->pos.x + i, slider->pos.y},
        (sfVector2f){3, slider->size.y},
        (sfColor){127, 191, 255, i / slider->size.x * 255});
    }
    if (!my_strcmp(slider->name, "Opacity"))
        get_empty_pattern(s, 5, slider->pos,
        (sfVector2f){slider->size.x * ratio, slider->size.y});
    display_rect(s, (sfVector2f){slider->pos.x
    + slider->size.x * ratio - 2, slider->pos.y},
    (sfVector2f){4, slider->size.y}, (sfColor){127, 127, 127, 255});
    str = my_ftoa(slider->min);
    sub_slider(s, slider, is_float, str);
}

void display_radio(screen_t *s, shape_t *shape, char *str, int reverse)
{
    sfCircleShape_setPosition(s->circle, shape->pos);
    sfCircleShape_setRadius(s->circle, shape->size / 2);
    sfCircleShape_setOutlineColor(s->circle, (sfColor){127, 127, 127, 255});
    sfCircleShape_setOutlineThickness(s->circle, 1);
    sfCircleShape_setFillColor(s->circle, shape->state ?
    reverse ? sfBlack : sfWhite : reverse ? sfWhite : sfBlack);
    sfRenderWindow_drawCircleShape(s->window, s->circle, NULL);
    display_text(s, shape->name, (sfVector2f)
    {shape->pos.x + 20, shape->pos.y - 10}, sfBlack);
    if (get_pythagore(shape->pos, (sfVector2f) {s->mouse_pos.x -
    shape->size / 2, s->mouse_pos.y - shape->size / 2}) <= shape->size / 2
    && sfMouse_isButtonPressed(sfMouseLeft))
        shape->state = reverse;
    sfText_setString(s->text, str);
    display_text(s, str, (sfVector2f)
    {shape->pos.x + 17, shape->pos.y - 3.5}, sfBlack);
}

void display_brush_a(screen_t *s, brush_t *brush)
{
    display_text(s, brush->name, (sfVector2f){20, 50}, sfBlack);
    display_text(s, "Opacity :", (sfVector2f){20, 80 + s->map_size.y}, sfBlack);
    brush->opacity->pos = (sfVector2f){20, 100 + s->map_size.y};
    display_slider(s, brush->opacity, 1);
    display_text(s, "Size :", (sfVector2f){20, 130 + s->map_size.y}, sfBlack);
    brush->size->pos = (sfVector2f){20, 150 + s->map_size.y};
    display_slider(s, brush->size , 0);
    display_text(s, "Smooth :", (sfVector2f){20, 180 + s->map_size.y}, sfBlack);
    brush->smooth->pos = (sfVector2f){20, 200 + s->map_size.y};
    display_slider(s, brush->smooth, 1);
    display_color_map(s, s->map_pos, s->map_size);
    display_color_picker(s);
}

void display_brush_b(screen_t *s, brush_t *brush)
{
    display_text(s, "Eraser settings", (sfVector2f){20, 50}, sfBlack);
    display_text(s, "Size :", (sfVector2f){20, 80}, sfBlack);
    brush->size->pos = (sfVector2f){20, 100};
    sfRectangleShape_setOutlineThickness(s->rect, 0);
    display_slider(s, brush->size , 0);
    display_text(s, "Shape :", (sfVector2f){20, 137}, sfBlack);
    sfRectangleShape_setOutlineThickness(s->rect, 0);
    brush->shape->pos = (sfVector2f){20, 162};
    display_radio(s, brush->shape, "Square", 0);
    brush->shape->pos = (sfVector2f){20 + 100, 162};
    display_radio(s, brush->shape, "Circle", 1);
    display_rect(s, (sfVector2f){0, 183}, (sfVector2f)
    {s->size.x / 6, 1}, sfColor_fromRGBA(127, 127, 127, 255));
}

void display_brush(screen_t *s, brush_t *brush)
{
    my_strcmp(brush->name, "Eraser") ?
    display_brush_a(s, brush) : display_brush_b(s, brush);
    brush->smooth->size = (sfVector2f){s->size.x / 6 - 40, 10};
    brush->opacity->size = (sfVector2f){s->size.x / 6 - 40, 10};
    brush->size->size = (sfVector2f){s->size.x / 6 - 40, 10};
}
