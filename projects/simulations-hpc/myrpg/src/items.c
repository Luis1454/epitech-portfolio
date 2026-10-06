/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** items.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void setup_item(item_t *item, int id, char *name, int *datas)
{
    item[id].id = id;
    item[id].name = my_strdup(name);
    item[id].type = datas[0];
    item[id].value = datas[1];
    item[id].rarity = datas[2];
    item[id].level = datas[3];
    item[id].attack = datas[4];
    item[id].defense = datas[5];
    item[id].speed = datas[6];
    item[id].mana = datas[7];
    item[id].durability = datas[8];
}

void init_items(game_t *game)
{
    int *datas = malloc(sizeof(int) * 9);

    for (int i = 0; i < 9; i++)
        datas[i] = 0;
    game->items = malloc(sizeof(item_t) * 100);
    for (int i = 0; i < 100; i++) {
        game->items[i].name = NULL;
        game->items[i].id = -1;
    }
    init_name_items_line_one(game, datas);
}

item_t get_item_by_id(game_t *game, int id)
{
    for (int i = 0; i < 100; i++) {
        if (game->items[i].id == id)
            return game->items[i];
    }
    return game->items[99];
}

void display_item(game_t *game, sfVector2f pos, int id)
{
    sfSprite_setScale(game->item_sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setOrigin(game->item_sprite, (sfVector2f){16, 16});
    sfSprite_setTextureRect(game->item_sprite, (sfIntRect)
    {(id % 10) * 32, (id / 10) * 32, 32, 32});
    sfSprite_setPosition(game->item_sprite, pos);
    sfRenderWindow_drawSprite(game->window, game->item_sprite, NULL);
}
