/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** move_player.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"
#include "../include/my_macro_abs.h"

int check_trajectory(game_t *game, player_t *p, double x, double y)
{
    int delta = 0;

    for (int i = 0; i < MAX(x, y) + 1; i++) {
        delta = get_pos_alt(game, (sfVector2i){p->pos.x, p->pos.y}) -
        get_pos_alt(game, (sfVector2i){p->pos.x + x, p->pos.y + y});
        if (!(-1 <= delta && delta <= 1))
            return 0;
    }
    return 1;
}

void sub_get_move(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
    && game->player->pos.x >= 0 && check_trajectory(game, game->player,
    -MIN(game->player->speed / 100.0, game->player->pos.x), 0))
        game->player->pos.x -= MIN(game->player->speed / 100.0,
        game->player->pos.x);
    if ((sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
    && game->player->pos.x < game->map->size.x
    && check_trajectory(game, game->player, MIN(game->player->speed / 100.0,
        game->map->size.x - game->player->pos.x - 1), 0))
        game->player->pos.x += MIN(game->player->speed / 100.0,
            game->map->size.x - game->player->pos.x - 1);
}

void get_move(game_t *game)
{
    get_angle(game);
    sfSprite_setScale(game->player->sprite, (sfVector2f){
        game->map->rescale * game->player->reverse,
        game->map->rescale
    });
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    if ((sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyRight)) && game->player->pos.y >= 0
    && check_trajectory(game, game->player, 0, -MIN(game->player->speed / 100.0,
    game->player->pos.y)))
        game->player->pos.y -= MIN(game->player->speed / 100.0,
        game->player->pos.y);
    if ((sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
    && game->player->pos.y < game->map->size.y
    && check_trajectory(game, game->player, 0, MIN(game->player->speed / 100.0,
    game->map->size.y - game->player->pos.y - 1)))
        game->player->pos.y += MIN(game->player->speed / 100.0,
        game->map->size.y - game->player->pos.y - 1);
    sub_get_move(game);
}

int *set_int_tab(int *tab, int *args, int size)
{
    for (int i = 0; i < size; i++)
        tab[i] = args[i];
    return tab;
}

void display_value(game_t *game, sfVector2i pos, char *name, sfVector2f v)
{
    char *str = NULL;
    str = my_itoa((int)v.x, str);

    display_slider(game, (sfFloatRect){pos.x, pos.y, 200, 30},
    get_color_by_name(name), v.x / v.y);
    sfText_setCharacterSize(game->text, 25);
    sfText_setColor(game->text, sfWhite);
    add_text(game, game->text, name, (sfVector2f){90 + pos.x, 15 + pos.y});
    add_text(game, game->text, str, (sfVector2f){135 + pos.x, 15 + pos.y});
    sfText_setCharacterSize(game->text, 45);
    sfText_setColor(game->text, sfBlack);
    free(str);
}
