/*
** EPITECH PROJECT, 2022
** myrpg_final
** File description:
** open_map.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

int display_open(game_t *game)
{
    add_rect(game, (sfVector2f){0.1 * game->size.x, 0.1 * game->size.y},
    (sfVector2f){0.8 * game->size.x, 0.8 * game->size.y},
    (sfColor){0, 0, 0, 191});
    display_folder(game, game->path, (sfVector2f){0.15 * game->size.x, 0.15 *
    game->size.y});
    sfText_setCharacterSize(game->text, 45);
    sfText_setColor(game->text, sfBlack);
    sfText_setStyle(game->text, 0);
    return 0;
}
