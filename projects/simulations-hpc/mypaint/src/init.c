/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** init functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/mylist.h"
#include "../include/my_macro_abs.h"

void init_eraser(screen_t *s)
{
    add_brush(s, 30, sfColor_fromRGBA(255, 255, 255, 255), 0);
    s->eraser = get_brush_by_id(s, 0);
    if (s->eraser->name)
        free(s->eraser->name);
    s->eraser->name = my_strdup("Eraser");
}

void init_circle(screen_t *s, int size, sfColor color)
{
    sfCircleShape_setFillColor(s->circle, sfTransparent);
    sfCircleShape_setRadius(s->circle, size / 2);
    sfCircleShape_setOutlineColor(s->circle, color);
    sfCircleShape_setOutlineThickness(s->circle, 2);
}

void sub_init_toolbar(screen_t *s, sfVector2f size)
{
    append_button_child(get_button_by_name(s->toolbar, "File"),
    "New", (frame_t){(sfVector2f){5, 25}, size});
    append_button_child(get_button_by_name(s->toolbar, "File"),
    "Open", (frame_t){(sfVector2f){5, 45}, size});
    append_button_child(get_button_by_name(s->toolbar, "File"),
    "Save", (frame_t){(sfVector2f){5, 65}, size});
    append_button_child(get_button_by_name(s->toolbar, "File"),
    "Save as", (frame_t){(sfVector2f){5, 85}, size});
    append_button_child(get_button_by_name(s->toolbar, "File"),
    "Exit", (frame_t){(sfVector2f){5, 105}, size});
    append_button_child(get_button_by_name(s->toolbar, "Edit"),
    "Pencil", (frame_t){(sfVector2f){45, 25}, size});
    append_button_child(get_button_by_name(s->toolbar, "Edit"),
    "Eraser", (frame_t){(sfVector2f){45, 45}, size});
    append_button_child(get_button_by_name(s->toolbar, "Help"),
    "About", (frame_t){(sfVector2f){85, 25}, size});
    append_button_child(get_button_by_name(s->toolbar, "Help"),
    "Help", (frame_t){(sfVector2f){85, 45}, size});
}

void init_toolbar(screen_t *s)
{
    sfColor bg = sfTransparent;
    sfColor hover = (sfColor){0, 0, 0, 50};
    sfVector2f btn_size = (sfVector2f){35, s->size.y / 45};
    sfVector2f size = (sfVector2f){60, 20};

    s->toolbar = create_button("File", (frame_t)
    {(sfVector2f){5, 0}, btn_size}, bg, hover);
    append_button(s->toolbar, "Edit", (frame_t)
    {(sfVector2f){45, 0}, btn_size});
    append_button(s->toolbar, "Help", (frame_t)
    {(sfVector2f){85, 0}, btn_size});
    sub_init_toolbar(s, size);
}
