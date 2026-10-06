/*
** EPITECH PROJECT, 2023
** pixel.c
** File description:
** pixel functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void sub_edit_pixel(screen_t *s, sfVector2i a, sfVector2i b, sfColor color)
{
    sfColor *c;
    double opacity = 0;
    int size = a.x;
    int i = a.y;
    int j = b.x;
    int is_eraser = b.y;
    double dist = dist = get_pythagore((sfVector2f)
    {i, j}, (sfVector2f){size / 2, size / 2});

    opacity = (1 - s->current_brush->smooth->value) *
    (1 - dist / (size / 2)) * s->current_brush->opacity->value;
    opacity *= (opacity < 1 && opacity > 0);
    c = &s->image->pixels[(int)((s->mouse_pos.y + j - size / 2 -
    s->draw_area.a.y) * s->image->size.x +
    s->mouse_pos.x + i - size / 2 - s->draw_area.a.x)];
    *c = is_eraser ? sfTransparent : mix_color(*c,
    color, opacity > 1 ? 1 : opacity < 0 ? 0 : opacity);
}

void edit_pixel(screen_t *s, sfColor color, int size, frame_t box)
{
    double dist = 0;
    int is_eraser = !my_strcmp(s->current_brush->name, "Eraser");

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            dist = get_pythagore((sfVector2f){i, j},
            (sfVector2f){size / 2, size / 2});
            (dist <= size / 2 || (is_eraser
            && !s->current_brush->shape->state))
            && is_in_box(box, (sfVector2f){s->mouse_pos.x + i - size / 2,
            s->mouse_pos.y + j - size / 2}) ?
            sub_edit_pixel(s, (sfVector2i){size, i},
            (sfVector2i){j, is_eraser}, color) : 0;
        }
}
