/*
** EPITECH PROJECT, 2021
** get_functions.c
** File description:
** get functions
*/

#include "../includes/include.h"
#include "../includes/my.h"

int get_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return 1;
}

int get_warning(int nb, sfRectangleShape *rect, Plane plane,
Plane p[nb])
{
    if (get_collide(nb, 75, plane, p))
        sfRectangleShape_setOutlineThickness(rect, 3);
    else
        sfRectangleShape_setOutlineThickness(rect, 1);

    if (get_collide(nb, 100, plane, p))
        sfRectangleShape_setOutlineColor(rect, sfRed);
    else if (get_collide(nb, 150, plane, p))
        sfRectangleShape_setOutlineColor(rect, sfColor_fromRGB(255, 125, 0));
}

void init_A(Screen *s)
{
    s->off;
    s->Xsize = 1920;
    s->Ysize = 1080;
    s->shutter = 60;
    s->pixels = malloc(sizeof(sfColor) * s->Xsize * s->Ysize);
    s->mode.width = s->Xsize;
    s->mode.height = s->Ysize;
    s->mode.bitsPerPixel = 32;
    s->window;
    s->event;
    s->trace = sfTexture_create(s->Xsize, s->Ysize);
}

void init_B(Screen *s)
{
    s->sprite = sfSprite_create();
    s->traceMap = sfSprite_create();
    s->pln_sprite = sfSprite_create();
    s->twr_sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile("textures/map.png", NULL);
    s->pln_texture = sfTexture_createFromFile("textures/plane.png", NULL);
    s->twr_texture = sfTexture_createFromFile("textures/tower.png", NULL);
    s->text = sfText_create();
    s->font = sfFont_createFromFile("fonts/arial.ttf");
    s->circle = sfCircleShape_create();
    s->rect = sfRectangleShape_create();
}
