/*
** EPITECH PROJECT, 2023
** loop.c
** File description:
** loop functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void sub_loop_a(screen_t *s)
{
    while (sfRenderWindow_pollEvent(s->window, &s->event))
        if (s->event.type == sfEvtClosed
        || (s->event.type == sfEvtKeyPressed
        && s->event.key.code == sfKeyEscape))
            sfRenderWindow_close(s->window);
    compute_draw_area(s);
    s->size = (sfVector2i){sfRenderWindow_getSize(s->window).x,
    sfRenderWindow_getSize(s->window).y};
    sfRectangleShape_setOutlineThickness(s->rect, 2);
    display_rect(s, (sfVector2f){0, 0}, (sfVector2f){s->size.x / 6,
    s->size.y}, sfColor_fromRGB(191, 191, 191));
    display_rect(s, (sfVector2f){s->size.x * 6.0 / 7.0, 0}, (sfVector2f)
    {s->size.x / 7.0, s->size.y}, sfColor_fromRGB(191, 191, 191));
    display_rect(s, (sfVector2f){0, 0}, (sfVector2f){s->size.x,
    s->size.y / 45}, sfColor_fromRGB(191, 191, 191));
    display_rect(s, (sfVector2f){0, s->size.y * 39 / 40},
    (sfVector2f){s->size.x, s->size.y / 40}, sfColor_fromRGB(191, 191, 191));
    get_empty_pattern(s, GRID_SIZE, s->draw_area.a, s->draw_area.b);
}

void sub_loop_b(screen_t *s)
{
    sfTexture_updateFromPixels(s->image->texture, (sfUint8 *)
    s->image->pixels, s->image->size.x, s->image->size.y, 0, 0);
    sfSprite_setPosition(s->image->sprite,
    (sfVector2f){s->draw_area.a.x, s->draw_area.a.y});
    sfRenderWindow_drawSprite(s->window, s->image->sprite, NULL);
    display_grid(s, sfColor_fromRGBA(127, 127, 127, 127), GRID_SIZE);
    interpolate_brush(s, (sfVector2f){s->mouse_pos.x, s->mouse_pos.y});
    is_in_box((frame_t){(sfVector2f){s->draw_area.a.x -
    s->current_brush->size->value / 2, s->draw_area.a.y -
    s->current_brush->size->value / 2},
    (sfVector2f){s->draw_area.b.x + s->current_brush->size->value,
    s->draw_area.b.y + s->current_brush->size->value}}, (sfVector2f)
    {s->mouse_pos.x, s->mouse_pos.y}) ? display_brush_circle(s) : 0;
    display_brush(s, s->current_brush);
    display_toolbar(s);
}

int main_loop(screen_t *s)
{
    while (sfRenderWindow_isOpen(s->window) && s->state) {
        sub_loop_a(s);
        sub_loop_b(s);
        if (sfMouse_isButtonPressed(sfMouseLeft) && is_in_box((frame_t)
        {s->map_pos, s->map_size}, (sfVector2f)
        {s->mouse_pos.x, s->mouse_pos.y}))
            s->current_brush->color = get_color_from_map(s->map_pos,
            s->map_size, (sfVector2f){s->mouse_pos.x, s->mouse_pos.y});
        sfCircleShape_setOutlineColor(s->circle, s->current_brush->color);
        slider_handler(s);
        panel_handler(s);
        sfRenderWindow_display(s->window);
        sfRenderWindow_clear(s->window, sfColor_fromRGB(127, 127, 127));
        s->mouse_pos = sfMouse_getPositionRenderWindow(s->window);
    }
    return 0;
}
