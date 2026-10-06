/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** display_game.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

void display_toolbar(game_t *game)
{
    char *str = NULL;
    sfVector2i center = {game->size.x / 2, game->size.y * 0.9};

    for (int i = 0; i < 10; i++) {
        sfRectangleShape_setOutlineThickness(game->rect, 3);
        sfRectangleShape_setOutlineColor(game->rect, (sfColor)
        {105, 78, 52, 255});
        add_rect(game, (sfVector2f){center.x - 300 + i * 60, center.y},
        (sfVector2f){50, 50}, (sfColor){212, 193, 174, 255});
        sfText_setCharacterSize(game->text, 17);
        add_text(game, game->text,
        my_itoa(game->player->inventory[i / 10][i % 10], str), (sfVector2f)
        {center.x - 300 + i * 60 + 43, center.y + 43});
        free(str);
        display_item(game, (sfVector2f){center.x - 300 + i * 60 + 25,
        center.y + 25}, game->player->inventory[i / 10][i % 10]);
        sfText_setCharacterSize(game->text, 45);
    }
    if (game->player->is_inventory)
        display_inventory(game);
}

void sub_display_play(game_t *game)
{
    sfRenderWindow_clear(game->window, sfWhite);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyI) && game->player->last_i_state) {
        game->player->is_inventory = !game->player->is_inventory;
        game->player->last_i_state = 0;
    } else if (!sfKeyboard_isKeyPressed(sfKeyI))
        game->player->last_i_state = 1;
    get_move(game);
}

int display_play(game_t *game)
{
    sub_display_play(game);
    display_map_from_data(game, game->map);
    display_toolbar(game);
    sfRectangleShape_setOutlineThickness(game->rect, 0);
    display_value(game, (sfVector2i){10, 10}, "Life :", (sfVector2f)
    {game->player->life, (game->player->max_life ? game->player->max_life
    : 100)});
    display_value(game, (sfVector2i){10, 80}, "Mana :", (sfVector2f)
    {game->player->mana, (game->player->max_mana ? game->player->max_mana
    : 100)});
    game->player->life -= 0.01 * (game->player->life >= 0);
    return 0;
}

int display_game(game_t *game)
{
    zoom_map(game->map);
    if (game->menu_id == get_id_by_menu_name(game->menu, "New game"))
        return display_play(game);
    if (game->menu_id == get_id_by_menu_name(game->menu, "Open map"))
        return display_open(game);
    if (game->menu_id == get_id_by_menu_name(game->menu, "About"))
        return display_about(game);
    if (game->menu_id == get_id_by_menu_name(game->menu, "Settings"))
        return display_settings(game);
    return display_menu(game);
}
