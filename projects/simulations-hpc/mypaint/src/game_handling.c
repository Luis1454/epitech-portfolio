/*
** EPITECH PROJECT, 2022
** game_handling.c
** File description:
** functions for the game
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void add_text(screen_t *s, sfText *t, char *str, sfVector2f pos)
{
    sfText_setString(t, str);
    sfText_setPosition(t, pos);
    sfRenderWindow_drawText(s->window, t, NULL);
}

void update_limits(sfVector2i *limits, sfVector2i point)
{
    if (point.x < limits[0].x)
        limits[0].x = point.x;
    if (point.x > limits[1].x)
        limits[1].x = point.x;
    if (point.y < limits[0].y)
        limits[0].y = point.y;
    if (point.y > limits[1].y)
        limits[1].y = point.y;
}

void set_all_sate(button_t *b, int state)
{
    while (b) {
        b->state = state;
        b = b->next;
    }
}

void update_last_clicks(screen_t *s)
{
    int len = len_list(s->last_clicks);

    add_node(&s->last_clicks, s->mouse_pos);
    if (2 <= len && len <= HIST_LEN)
        remove_last_node(&s->last_clicks);
}

void compute_draw_area(screen_t *s)
{
    sfVector2i offset = (sfVector2i){20, 20};

    s->draw_area.b = (sfVector2f){s->image->size.x, s->image->size.y};
    s->draw_area.a = (sfVector2f){s->size.x / 4 + offset.x,
    s->size.y / 20 + offset.y};
}
