/*
** EPITECH PROJECT, 2023
** text.c
** File description:
** text handling
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void add_text(game_t *game, sfText *t, char *str, sfVector2f pos)
{
    sfFloatRect size = {0, 0, 0, 0};

    sfText_setString(t, str);
    size = sfText_getGlobalBounds(t);
    sfText_setOrigin(t, (sfVector2f){size.width / 2.0, size.height});
    sfText_setPosition(t, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(game->window, t, NULL);
    sfText_setOutlineThickness(t, 0);
}

void add_text_at(game_t *game, sfText *t, char *str, sfVector2f pos)
{
    sfText_setString(t, str);
    sfText_setOrigin(t, (sfVector2f){0, 0});
    sfText_setPosition(t, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(game->window, t, NULL);
    sfText_setOutlineThickness(t, 0);
}

void init_text(game_t *game)
{
    game->font = sfFont_createFromFile("assets/fonts/med.ttf");
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 45);
    sfText_setColor(game->text, sfBlack);
}
