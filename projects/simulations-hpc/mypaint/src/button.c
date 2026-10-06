/*
** EPITECH PROJECT, 2023
** button.c
** File description:
** button functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

button_t *create_button(char *name,
frame_t frame, sfColor color, sfColor hover)
{
    button_t *b = malloc(sizeof(button_t));

    if (!b)
        return NULL;
    b->name = my_strdup(name);
    b->box = frame;
    b->color = color;
    b->hover = hover;
    b->state = 0;
    b->visible = 0;
    b->next = NULL;
    b->child = NULL;
    return b;
}

void append_button(button_t *b, char *name, frame_t frame)
{
    button_t *new = create_button(name, frame, b->color, b->hover);

    if (!new)
        return;
    while (b->next)
        b = b->next;
    b->next = new;
}

void append_button_child(button_t *b, char *name, frame_t frame)
{
    button_t *new = create_button(name, frame, b->color, b->hover);

    if (!new)
        return;
    while (b->child)
        b = b->child;
    b->child = new;
}

void sub_display_toolbar(screen_t *s, button_t *b)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        b->visible = is_in_box(b->box,
        (sfVector2f){s->mouse_pos.x, s->mouse_pos.y});
        for (button_t *c = b->child; c; c = c->child)
            c->state = (is_in_box(c->box, (sfVector2f)
            {s->mouse_pos.x, s->mouse_pos.y}) ? 1 : c->state);
    }
    if (b->visible) {
        display_rect(s, (sfVector2f){b->box.a.x, b->box.a.y + 25},
        (sfVector2f){get_nb_child(b->child) ? 60 : b->box.b.x, 20 *
        get_nb_child(b) - 20 + (get_nb_child(b->child) ? 0 : 3)}, sfWhite);
        b->child ? display_child(s, b->child, sfFalse) : 0;
    }
}

void display_toolbar(screen_t *s)
{
    for (button_t *b = s->toolbar; b; b = b->next)
        display_button(s, b, sfFalse);
    for (button_t *b = s->toolbar; b; b = b->next)
        sub_display_toolbar(s, b);
}
