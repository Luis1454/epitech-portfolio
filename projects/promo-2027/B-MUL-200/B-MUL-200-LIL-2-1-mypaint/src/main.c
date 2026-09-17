/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void sub_interpolate(screen_t *s, sfVector2f pos)
{
    s->interpolation = get_pythagore((sfVector2f)
    {s->last_clicks->pos.x, s->last_clicks->pos.y}, pos);
    if (!my_strcmp(s->current_brush->name, "Eraser"))
        edit_pixel(s, s->current_brush->color,
        s->current_brush->size->value, s->draw_area);
    s->interpolation = s->interpolation >
    MAX_INTERPOLATION ? MAX_INTERPOLATION : s->interpolation;
    for (int i = 1; i < s->interpolation; i++) {
        s->mouse_pos.x = s->last_clicks->pos.x
        + (pos.x - s->last_clicks->pos.x) * i / s->interpolation;
        s->mouse_pos.y = s->last_clicks->pos.y
        + (pos.y - s->last_clicks->pos.y) * i / s->interpolation;
        edit_pixel(s, s->current_brush->color,
        s->current_brush->size->value, s->draw_area);
    }
}

void interpolate_brush(screen_t *s, sfVector2f pos)
{
    int state = sfMouse_isButtonPressed(sfMouseLeft);

    if (s->last_clicks == NULL) {
        add_node(&s->last_clicks, s->mouse_pos);
        return;
    }
    if (state && s->last_state)
        sub_interpolate(s, pos);
    state ? update_last_clicks(s) : 0;
    s->last_state = state;
}

int sub_init(screen_t *s)
{
    s->size = (sfVector2i){1920, 1080};
    s->rect = sfRectangleShape_create();
    s->path = malloc(sizeof(char) * 8192);
    s->path = my_memset(s->path, 0, 8192);
    s->path = my_strcpy(s->path, "/");
    s->mouse_pos = (sfVector2i){s->size.x / 2, s->size.y / 2};
    s->map_pos = (sfVector2f){20, 75};
    s->map_size = (sfVector2f){s->size.x / 6 - 40, s->size.x / 6 - 40};
    s->picker_size = (sfVector2f){40, 30};
    s->picker_pos = (sfVector2f){s->size.x / 12 - 10 -
    s->picker_size.x / 2, s->map_pos.y + s->map_size.y + 165};
    s->last_clicks = NULL;
    s->help = get_split_from_file("README.usage");
    if (!s->help)
        return 84;
    s->circle = sfCircleShape_create();
    init_circle(s, 30, sfColor_fromRGBA(50, 174, 192, 255));
    add_brush(s, 30, sfColor_fromRGBA(50, 174, 192, 255), 0.5);
    init_eraser(s);
    return 0;
}

int init_paint(screen_t *s)
{
    if (sub_init(s))
        return 84;
    s->current_brush = get_brush_by_id(s, 1);
    s->file = NULL;
    sfRectangleShape_setOutlineColor(s->rect, sfColor_fromRGB(168, 168, 168));
    s->state = 1;
    s->text = sfText_create();
    s->font = sfFont_createFromFile("fonts/arial.ttf");
    sfText_setFont(s->text, s->font);
    s->window = sfRenderWindow_create((sfVideoMode){s->size.x, s->size.y, 32},
        "My Paint", sfResize | sfClose, NULL);
    if (!s->window || !s->rect || !s->text || !s->font)
        return 84;
    if (create_new(s, (sfVector2i){800, 600}, "untitled.jpg"))
        return 84;
    sfRenderWindow_setTitle(s->window, "My Paint");
    init_toolbar(s);
    return main_loop(s);
}

int main(int argc, char **argv, char **env)
{
    screen_t *s = malloc(sizeof(screen_t));

    argv = argv;
    if (!env || !env[0] || argc != 1 || !s || init_paint(s))
        return 84;
    return 0;
}
