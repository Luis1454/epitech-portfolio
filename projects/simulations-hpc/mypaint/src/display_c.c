/*
** EPITECH PROJECT, 2023
** display_c.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void display_open_panel(screen_t *s, sfVector2f pos)
{
    sfVector2f size = {800, 400};
    frame_t frame = {(sfVector2f){pos.x + size.x / 2 - 70,
    pos.y + size.y / 2 - 30}, (sfVector2f){140, 60}};

    sfRectangleShape_setOutlineThickness(s->rect, 0);
    display_rect(s, (sfVector2f){pos.x - size.x / 2, pos.y - size.y / 2},
    (sfVector2f){size.x, size.y}, sfWhite);
    display_folder(s, s->path, (sfVector2f)
    {pos.x - size.x / 2 + 20, pos.y - size.y / 2 + 20});
    display_text(s, "Cancel", (sfVector2f)
    {pos.x + size.x / 2 - 70, pos.y + size.y / 2 - 30}, sfBlack);
    if (is_in_box(frame, (sfVector2f){s->mouse_pos.x, s->mouse_pos.y})
    && s->event.type == sfEvtMouseButtonPressed)
        get_button_by_name(s->toolbar, "Open")->state = 0;
}

void display_searchbar(screen_t *s, sfVector2f pos, sfVector2f size)
{
    sfRectangleShape_setOutlineThickness(s->rect, 0);
    display_rect(s, (sfVector2f){pos.x, pos.y},
    (sfVector2f){size.x - 40, 30}, sfWhite);
    display_text(s, "Search", (sfVector2f){pos.x + 10, pos.y + 5}, sfBlack);
}

void display_save_panel(screen_t *s, button_t *b, int exists)
{
    if (!exists)
        save_image(s);
    b->state = 0;
}

void display_brush_circle(screen_t *s)
{
    sfVector2f pos = {s->mouse_pos.x - s->current_brush->size->value / 2,
    s->mouse_pos.y - s->current_brush->size->value / 2};
    sfVector2f size = {s->current_brush->size->value,
    s->current_brush->size->value};

    if (!my_strcmp(s->current_brush->name, "Eraser")) {
        sfRectangleShape_setOutlineThickness(s->rect, 0);
        display_rect(s, (sfVector2f){pos.x, pos.y - size.y * (2.0 / 3)},
        (sfVector2f){size.x, size.y * (2.0 / 3)},
        sfColor_fromRGBA(93, 139, 173, 191));
        sfRectangleShape_setOutlineThickness(s->rect, 0);
        display_rect(s, pos, size, sfColor_fromRGBA(235, 130, 129, 191));
    } else {
        sfCircleShape_setFillColor(s->circle, sfTransparent);
        sfCircleShape_setRadius(s->circle, s->current_brush->size->value / 2);
        sfCircleShape_setPosition(s->circle, (sfVector2f)
        {s->mouse_pos.x - s->current_brush->size->value / 2,
        s->mouse_pos.y - s->current_brush->size->value / 2});
        sfRenderWindow_drawCircleShape(s->window, s->circle, NULL);
    }
}

void display_button(screen_t *s, button_t *b, int active)
{
    sfRectangleShape_setOutlineThickness(s->rect, 0);
    display_rect(s, (sfVector2f){b->box.a.x, b->box.a.y},
    (sfVector2f){b->box.b.x, b->box.b.y}, (is_in_box(b->box, (sfVector2f)
    {s->mouse_pos.x, s->mouse_pos.y}) || active) ? b->hover : b->color);
    display_text(s, b->name, (sfVector2f)
    {b->box.a.x + 5, b->box.a.y + 3}, sfBlack);
}
