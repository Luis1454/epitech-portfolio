/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_about_button.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

void about_display(game_t *game)
{
    sfText_setCharacterSize(game->text, 30);
    add_text(game, game->text, "Zoom", (sfVector2f)
    {0.5 * game->size.x, 0.5 * game->size.y});
    sfText_setCharacterSize(game->text, 19);
    add_text(game, game->text, "Pressed + key (zoom in) and - key (zoom out)",
    (sfVector2f)    {0.5 * game->size.x, 0.53 * game->size.y});
    sfText_setCharacterSize(game->text, 30);
    add_text(game, game->text, "print lnventory", (sfVector2f)
    {0.5 * game->size.x, 0.585 * game->size.y});
    sfText_setCharacterSize(game->text, 19);
    add_text(game, game->text, "Pressed i key", (sfVector2f)
    {0.5 * game->size.x, 0.61 * game->size.y});
    sfText_setCharacterSize(game->text, 30);
    sfText_setColor(game->text, sfBlack);
    sfText_setCharacterSize(game->text, 45);
}

void sub_display_about(game_t *game)
{
    add_text(game, game->text, "Move", (sfVector2f)
    {0.5 * game->size.x, 0.285 * game->size.y});
    sfText_setCharacterSize(game->text, 19);
    add_text(game, game->text,
    "z (up), s (down), q (left), d (right)  keys or Arrow keys",
    (sfVector2f){0.5 * game->size.x, 0.32 * game->size.y});
    sfText_setCharacterSize(game->text, 30);
    add_text(game, game->text, "Volume sound and Sound click volume",
    (sfVector2f){0.5 * game->size.x, 0.385 * game->size.y});
    sfText_setCharacterSize(game->text, 19);
    add_text(game, game->text, " p(+) and m(-) for the music volume",
    (sfVector2f)
    {0.5 * game->size.x, 0.42 * game->size.y});
    add_text(game, game->text, " o(+) and l(-) for the sound volume",
    (sfVector2f)
    {0.5 * game->size.x, 0.442 * game->size.y});
    about_display(game);
}

int display_about(game_t *game)
{
    add_rect(game, (sfVector2f){0.1 * game->size.x, 0.1 * game->size.y},
    (sfVector2f){0.8 * game->size.x, 0.8 * game->size.y},
    (sfColor){0, 0, 0, 191});
    sfText_setCharacterSize(game->text, 30);
    sfText_setColor(game->text, sfWhite);
    add_text(game, game->text, "Help", (sfVector2f)
    {0.5 * game->size.x, 0.15 * game->size.y});
    add_text(game, game->text, "Exit a window", (sfVector2f)
    {0.5 * game->size.x, 0.2 * game->size.y});
    sfText_setCharacterSize(game->text, 19);
    add_text(game, game->text, "Pressed Escape key", (sfVector2f)
    {0.5 * game->size.x, 0.23 * game->size.y});
    sfText_setCharacterSize(game->text, 30);
    sub_display_about(game);
    return 0;
}
