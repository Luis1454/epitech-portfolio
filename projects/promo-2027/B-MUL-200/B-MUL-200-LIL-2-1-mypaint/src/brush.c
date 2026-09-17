/*
** EPITECH PROJECT, 2023
** brush.c
** File description:
** brush file
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

shape_t *create_shape(sfVector2f pos, sfColor color, int size, int state)
{
    shape_t *shape = malloc(sizeof(shape_t));

    if (!shape)
        return NULL;
    shape->pos = pos;
    shape->size = size;
    shape->name = NULL;
    shape->color = color;
    shape->state = state;
    return shape;
}

brush_t *create_brush(int size, sfColor color, double smooth, char *name)
{
    brush_t *brush = malloc(sizeof(brush_t));

    if (!brush)
        return NULL;
    brush->name = my_strdup(name);
    brush->color = color;
    brush->bg_color = sfWhite;
    brush->shape = create_shape((sfVector2f){0, 0}, sfTransparent, 10, 0);
    brush->smooth = create_slider((sfVector2f){100, 365},
    (sfVector2f){200, 10}, (sfVector2f){0, 1}, "Smooth");
    brush->smooth->value = smooth;
    brush->next = NULL;
    brush->opacity = create_slider((sfVector2f){100, 305},
    (sfVector2f){200, 10}, (sfVector2f){0, 1}, "Opacity");
    brush->opacity->value = 1;
    brush->size = create_slider((sfVector2f){100, 335},
    (sfVector2f){200, 10}, (sfVector2f){1, 400}, "Size");
    brush->size->value = (double)size;
    return brush;
}

void add_brush(screen_t *s, int size, sfColor color, double smooth)
{
    brush_t *new = create_brush(size, color, smooth, "Brush #1");

    if (!new)
        return;
    new->next = s->brush;
    s->brush = new;
}

brush_t *get_brush_by_id(screen_t *s, int id)
{
    brush_t *tmp = s->brush;

    for (int i = 0; i < id; i++)
        tmp = tmp->next;
    return tmp;
}
