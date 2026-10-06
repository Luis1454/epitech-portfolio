/*
** EPITECH PROJECT, 2023
** slider.c
** File description:
** slider functions
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void add_rect(game_t *game, sfVector2f pos, sfVector2f size, sfColor color)
{
    sfRectangleShape_setPosition(game->rect, pos);
    sfRectangleShape_setSize(game->rect, size);
    sfRectangleShape_setFillColor(game->rect, color);
    sfRectangleShape_setOutlineThickness(game->rect, 2);
    sfRenderWindow_drawRectangleShape(game->window, game->rect, NULL);
    sfRectangleShape_setOutlineThickness(game->rect, 0);
    sfRectangleShape_setFillColor(game->rect, sfTransparent);
}

void display_slider(game_t *game, sfFloatRect rect,
sfColor color, double factor)
{
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};

    add_rect(game, pos, size, (sfColor){212, 193, 174, 255});
    add_rect(game, pos, (sfVector2f){size.x * factor, size.y}, color);
}

void display_vslider(game_t *game, sfFloatRect rect,
sfColor color, double factor)
{
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};

    add_rect(game, pos, size, (sfColor){212, 193, 174, 255});
    add_rect(game, pos, (sfVector2f){size.x, size.y * factor}, color);
}
