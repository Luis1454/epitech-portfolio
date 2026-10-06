/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** init_menu.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

int init_texture(game_t *game)
{
    game->texture = malloc(sizeof(texture_t));
    if (!game->texture)
        return 84;
    game->texture->t = malloc(sizeof(sfText *) * 3);
    if (!game->texture->t)
        return 84;
    game->texture->t[0] = sfTexture_createFromFile("assets/textures/menu.jpg",
    NULL);
    game->texture->t[1] = sfTexture_createFromFile("assets/textures/about.png",
    NULL);
    game->texture->t[2] = sfTexture_createFromFile("assets/textures/menu.jpg",
    NULL);
    game->texture->iso = sfTexture_createFromFile("assets/textures/iso.png",
    NULL);
    game->texture->items = sfTexture_createFromFile("assets/textures/items.png",
    NULL);
    return 0;
}

void print_menu_button(game_t *game, menu_t *menu)
{
    menu = get_menu_by_name(game->menu, "Start");
    append_button(&menu->buttons, "New game", 0, (sfIntRect)
    {game->size.x / 2.0 - 200, game->size.y / 2.0 - 85, 195, 75});
    append_button(&menu->buttons, "Open map", 0, (sfIntRect)
    {game->size.x / 2.0 + 5, game->size.y / 2.0 - 85, 195, 75});
    append_button(&menu->buttons, "Settings", 0, (sfIntRect)
    {game->size.x / 2.0 - 200, game->size.y / 2.0, 195, 75});
    append_button(&menu->buttons, "About", 0, (sfIntRect)
    {game->size.x / 2.0 + 5, game->size.y / 2.0, 195, 75});
    append_button(&menu->buttons, "Quit", 0, (sfIntRect)
    {game->size.x / 2.0 - 200, game->size.y / 2.0 + 85, 400, 50});
    menu = get_menu_by_name(game->menu, "About");
}

int init_menu(game_t *game)
{
    menu_t *menu = NULL;
    game->menu = NULL;

    append_menu(&game->menu, "Start");
    append_menu(&game->menu, "New game");
    append_menu(&game->menu, "Open map");
    append_menu(&game->menu, "About");
    append_menu(&game->menu, "Settings");
    print_menu_button(game, menu);
    game->menu_id = get_id_by_menu_name(game->menu, "Start");
    return 0;
}

int is_in_rect(sfIntRect rect, sfVector2i mouse)
{
    return mouse.x >= rect.left && mouse.x <= rect.left + rect.width
    && mouse.y >= rect.top && mouse.y <= rect.top + rect.height;
}
