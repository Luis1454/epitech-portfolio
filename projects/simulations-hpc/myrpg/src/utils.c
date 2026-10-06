/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** utils.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"
#include "../include/my_macro_abs.h"

int get_pos_alt(game_t *game, sfVector2i pos)
{
    int alt = 0;
    int *tab = malloc(sizeof(int) * 5);

    tab = set_int_tab(tab, (int[]){51, 104, 74, 319, 41}, 5);
    for (; !contain_int(game->map->data[alt][pos.y][pos.x],
    tab, 5) && alt < 4; alt++);
    free(tab);
    return alt;
}

void get_angle(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp)) {
        game->player->reverse = -1;
        game->player->rect = (sfIntRect){88, 0, 22, 48};
    } else if (sfKeyboard_isKeyPressed(sfKeyQ) ||
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        game->player->reverse = -1;
        game->player->rect = (sfIntRect){0, 0, 22, 48};
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) ||
    sfKeyboard_isKeyPressed(sfKeyRight)) {
        game->player->reverse = 1;
        game->player->rect = (sfIntRect){88, 0, 22, 48};
    } else if (sfKeyboard_isKeyPressed(sfKeyS) ||
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        game->player->reverse = 1;
        game->player->rect = (sfIntRect){0, 0, 22, 48};
    }
}
