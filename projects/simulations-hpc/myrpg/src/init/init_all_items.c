/*
** EPITECH PROJECT, 2022
** myrpg_final
** File description:
** init_all_items.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

void init_name_items_line_five(game_t *game, int *datas)
{
    setup_item(game->items, 50, "Snail",  datas);
    setup_item(game->items, 51, "Big Key",  datas);
    setup_item(game->items, 52, "Key",  datas);
    setup_item(game->items, 53, "Key Chain",  datas);
    setup_item(game->items, 54, "Blue Vial",  datas);
    setup_item(game->items, 55, "Test Tube",  datas);
    setup_item(game->items, 56, "Green Vial",  datas);
    setup_item(game->items, 60, "Heal Stone",  datas);
    setup_item(game->items, 61, "xp Stone",  datas);
    setup_item(game->items, 62, "Mana Stone",  datas);
    setup_item(game->items, 70, "Wooden Sword",  datas);
    setup_item(game->items, 71, "Little Stick",  datas);
    setup_item(game->items, 72, "Little Axe",  datas);
    setup_item(game->items, 73, "Little Bow",  datas);
    setup_item(game->items, 74, "Blue Low Torch",  datas);
}

void init_name_items_line_four(game_t *game, int *datas)
{
    setup_item(game->items, 37, "Purple Bow",  datas);
    setup_item(game->items, 40, "Blue Torch",  datas);
    setup_item(game->items, 41, "Yellow Torch",  datas);
    setup_item(game->items, 42, "Big Blue Torch",  datas);
    setup_item(game->items, 43, "Dragon Torch",  datas);
    setup_item(game->items, 44, "Supreme Torch",  datas);
    setup_item(game->items, 44, "Purple Torch",  datas);
    setup_item(game->items, 45, "Green Torch",  datas);
}

void init_name_items_line_three(game_t *game, int *datas)
{
    setup_item(game->items, 20, "Masse",  datas);
    setup_item(game->items, 21, "Axe",  datas);
    setup_item(game->items, 22, "Halberd",  datas);
    setup_item(game->items, 23, "Red Axe",  datas);
    setup_item(game->items, 24, "Double Axe",  datas);
    setup_item(game->items, 25, "Thor's Hammer",  datas);
    setup_item(game->items, 26, "Double Red Axe",  datas);
    setup_item(game->items, 27, "Scourge",  datas);
    setup_item(game->items, 30, "Bow",  datas);
    setup_item(game->items, 31, "Big Bow",  datas);
    setup_item(game->items, 32, "Crossbow",  datas);
    setup_item(game->items, 33, "Large Bow",  datas);
    setup_item(game->items, 34, "Large Crossbow",  datas);
    setup_item(game->items, 35, "Elite Bow",  datas);
    setup_item(game->items, 36, "Ultimate Bow",  datas);
}

void init_name_items_line_two(game_t *game, int *datas)
{
    setup_item(game->items, 10, "Stick",  datas);
    setup_item(game->items, 11, "Spear",  datas);
    setup_item(game->items, 12, "Big Spear",  datas);
    setup_item(game->items, 13, "Red Spear",  datas);
    setup_item(game->items, 14, "Sharp Spear",  datas);
    setup_item(game->items, 15, "Giant Axe",  datas);
    setup_item(game->items, 16, "Poison Arrow",  datas);
    setup_item(game->items, 17, "Pigtail",  datas);
}

void init_name_items_line_one(game_t *game, int *datas)
{
    setup_item(game->items, 99, "None",  datas);
    setup_item(game->items, 0, "Mini Sword",  datas);
    setup_item(game->items, 1, "Sword",  datas);
    setup_item(game->items, 2, "Mini Saber",  datas);
    setup_item(game->items, 3, "Saber",  datas);
    setup_item(game->items, 4, "Big Sword",  datas);
    setup_item(game->items, 5, "Katana",  datas);
    setup_item(game->items, 6, "Knives",  datas);
    setup_item(game->items, 7, "Shuriken",  datas);
    init_name_items_line_five(game, datas);
    init_name_items_line_four(game, datas);
    init_name_items_line_three(game, datas);
    init_name_items_line_two(game, datas);
}
