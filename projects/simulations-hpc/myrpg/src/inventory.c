/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory functions
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void init_inventory(player_t *player)
{
    srand(time(NULL));
    player->inventory = malloc(6 * sizeof(int *));
    for (int i = 0; i < 6; i++) {
        player->inventory[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
            player->inventory[i][j] = (int)(rand() % 100);
    }
}

void sub_details(game_t *game, sfVector2f pos, int i, char *str)
{
    char *name[] = {"Name", "Type", "Value ", "Rarity", "Level",
    "Attack", "Defense", "Speed", "Mana", "Durability"};

    add_text_at(game, game->text, name[i],
    (sfVector2f){pos.x + 15, pos.y + 40 + 20 * i});
    add_text_at(game, game->text, ":",
    (sfVector2f){pos.x + 100, pos.y + 40 + 20 * i});
    add_text_at(game, game->text, str,
    (sfVector2f){pos.x + 120, pos.y + 40 + 20 * i});
    if (i)
        free(str);
}

void display_details(game_t *game, sfVector2f pos, int id)
{
    char *str = NULL;

    add_rect(game, pos, (sfVector2f){260, 250}, (sfColor){212, 193, 174, 255});
    sfText_setCharacterSize(game->text, 20);
    add_text_at(game, game->text, "ld", (sfVector2f){pos.x + 15, pos.y + 20});
    add_text_at(game, game->text, ":", (sfVector2f){pos.x + 100, pos.y + 20});
    add_text_at(game, game->text, my_itoa(id, str), (sfVector2f){pos.x + 120,
    pos.y + 20});
    sub_details(game, pos, 0, get_item_by_id(game, id).name);
    sub_details(game, pos, 1, my_itoa(get_item_by_id(game, id).type, str));
    sub_details(game, pos, 2, my_itoa(get_item_by_id(game, id).value, str));
    sub_details(game, pos, 3, my_itoa(get_item_by_id(game, id).rarity, str));
    sub_details(game, pos, 4, my_itoa(get_item_by_id(game, id).level, str));
    sub_details(game, pos, 5, my_itoa(get_item_by_id(game, id).attack, str));
    sub_details(game, pos, 6, my_itoa(get_item_by_id(game, id).defense, str));
    sub_details(game, pos, 7, my_itoa(get_item_by_id(game, id).speed, str));
    sub_details(game, pos, 8, my_itoa(get_item_by_id(game, id).mana, str));
    sub_details(game, pos, 9, my_itoa(get_item_by_id(game, id).durability,
    str));
    sfText_setCharacterSize(game->text, 45);
}

void display_inventory(game_t *game)
{
    sfVector2f pos = {game->size.x / 2 - 645 / 2, game->size.y / 2 - 450 / 2};
    sfVector2f size = {645, 450};

    add_rect(game, pos, size, (sfColor){212, 193, 174, 255});
    pos = (sfVector2f){pos.x + 25, pos.y + 75};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            add_rect(game, (sfVector2f){pos.x + 60 * j, pos.y + 60 * i},
            (sfVector2f){50, 50}, (sfColor){181, 159, 138, 255});
            display_item(game, (sfVector2f)
            {pos.x + 60 * j + 25, pos.y + 60 * i + 25},
            game->player->inventory[i][j]);
        }
        sfRectangleShape_setPosition(game->rect, pos);
    }
    sfText_setCharacterSize(game->text, 40);
    add_text(game, game->text, "lnventory",
    (sfVector2f){pos.x + 300, pos.y - 35});
    sfText_setCharacterSize(game->text, 45);
    check_hover(game, pos);
}
