/*
** EPITECH PROJECT, 2021
** core.c
** File description:
** core functions
*/

#include "../includes/my.h"
#include "../includes/my_world.h"

int sub_get_events(Screen *s, Map *map, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)
    && -80 < map->camera->Y)
        map->camera->Y--;
    if (sfKeyboard_isKeyPressed(sfKeyDown)
    && map->camera->Y < 0)
        map->camera->Y++;
}

int get_events(Screen *s, Map *map, sfEvent event)
{
    while (sfRenderWindow_pollEvent(s->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(s->window);
            sub_get_events(s, map, event);
        if (event.type == sfEvtMouseButtonReleased)
            button(s, event);
        map->camera->zoom *= (1 + event.mouseWheelScroll.delta / 50);
        if (map->camera->zoom > 10)
            map->camera->zoom = 10;
        else if (map->camera->zoom < 0.1)
            map->camera->zoom = 0.1;
        if (sfKeyboard_isKeyPressed(sfKeyDelete))
            reset_evelation(s, map);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            get_perlin_noise(s, map, min(s->Xsize, s->Ysize) / 3);
    }
    return 1;
}

void sub_my_world(Screen *s, Map *map)
{
    s->mouse_pos = sfMouse_getPosition(s->window);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        map->rot += 0.00005;
    else if (sfKeyboard_isKeyPressed(sfKeyRight))
        map->rot -= 0.00005;
    else if (sfKeyboard_isKeyPressed(sfKeySpace))
        map->rot = 0;
    map->time = sfClock_getElapsedTime(map->clock);
    if ((map->time.microseconds - map->last_time) / 10000 >= 1 / 60) {
    get_2d_map(s, map);
    sfClock_restart(map->clock);
    }
    map->last_time = map->time.microseconds;
    draw_map(s, map);
    build_axis(s, map);
    get_brush(s, map);
    get_events(s, map, s->event);
    sfRenderWindow_display(s->window);
    sfRenderWindow_clear(s->window, sfBlack);
    text(s);
}

int my_world(void)
{
    Screen *s = malloc(sizeof(Screen));
    Map *map = malloc(sizeof(Map));
    map->camera = malloc(sizeof(Camera));
    s->font = malloc(sizeof(Font_t));
    sfEvent event;

    init_screen(s);
    s->window = sfRenderWindow_create(s->mode, "my_world", sfClose, NULL);
    if (s->window == NULL)
        return 84;
    init_map(map);
    coord(s, map);
    reset_evelation(s, map);
    get_perlin_noise(s, map, min(s->Xsize, s->Ysize) / 3);
    init_font(s);
    while (sfRenderWindow_isOpen(s->window))
        sub_my_world(s, map);
    destroy_font(s);
    return 0;
}
