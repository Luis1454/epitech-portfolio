/*
** EPITECH PROJECT, 2022
** myrpg_final
** File description:
** check_hover.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void sub_check_hover(game_t *game, sfVector2f pos, int i)
{
    for (int j = 0; j < 10; j++)
        if (is_in_rect((sfIntRect){pos.x + 60 * j,
        pos.y + 60 * i, 50, 50}, game->mouse_pos)) {
            add_rect(game, (sfVector2f){pos.x + 60 * j, pos.y + 60 * i},
            (sfVector2f){50, 50}, (sfColor){255, 255, 255, 96});
            my_strcmp(get_item_by_id(game, game->player->inventory[i][j]).name,
            "None") ? display_details(game, (sfVector2f){pos.x + 60 * j + 45,
            pos.y + 60 * i - 45}, game->player->inventory[i][j]) : 0;
        }
}

void check_hover(game_t *game, sfVector2f pos)
{
    for (int i = 0; i < 6; i++)
        sub_check_hover(game, pos, i);
}
