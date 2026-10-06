/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** map functions
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void display_block_from_id(game_t *game, int id, sfVector2i pos,
double scale)
{
    sfFloatRect rect;

    sfSprite_setScale(game->map->sprite, (sfVector2f){scale, scale});
    rect = sfSprite_getLocalBounds(game->map->sprite);
    sfSprite_setPosition(game->map->sprite, (sfVector2f){pos.x, pos.y});
    sfSprite_setOrigin(game->map->sprite, (sfVector2f){rect.width / 2,
    rect.height / 2});
    sfSprite_setTexture(game->map->sprite, game->texture->iso, sfTrue);
    sfSprite_setTextureRect(game->map->sprite, (sfIntRect)
    {(id % 16) * 64, (id / 16) * 64, 64, 64});
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
}

sfVector2i id_to_iso(int id, sfVector2i size, sfVector2i offset,
double rescale)
{
    int x = id % size.x;
    int y = id / size.x;
    int iso_x = (x - y) * 32 * rescale;
    int iso_y = (x + y) * 16 * rescale;

    return (sfVector2i){iso_x + offset.x, iso_y + offset.y};
}

void sub_display_map_from_data(game_t *game, map_t *map, sfVector2i offset,
int i)
{
    sfVector2i cast = {0, 0};
    sfVector2i pos = {0, 0};

    for (int j = 0; j < map->size.x; j++) {
        for (int k = 0; k < 5; k++) {
            cast = id_to_iso(i * map->size.x + j,
            map->size, offset, map->rescale);
            pos = (sfVector2i){cast.x, cast.y - k * 32 * map->f};
            map->origin = !i && !j && !k ? pos : map->origin;
            display_block_from_id(game, map->data[k][i][j], pos, map->f);
        }
        if (game->player->pos.x >= j && game->player->pos.y >= i)
            display_player(game);
    }
}

void display_map_from_data(game_t *game, map_t *map)
{
    handle_animation(game);
    if (game->menu_id == get_id_by_menu_name(game->menu, "New game")) {
        map->f += (map->f < map->rescale ? 1.0 / (pow(map->f /
        map->rescale, 1.5) * 50 + 10) : 0) +
        sfKeyboard_isKeyPressed(sfKeyAdd) * game->map->zoom_speed;
        map->f > map->rescale ? map->f = map->rescale : 0;
    }
    sfVector2i offset = {game->size.x / 2, game->size.y / 2};
    sfVector2i project = id_to_iso(map->size.x * map->size.y / 2, map->size,
    (sfVector2i){0, 0}, map->rescale);
    offset.x -= project.x;
    offset.y -= project.y;

    for (int i = 0; i < map->size.y; i++)
        sub_display_map_from_data(game, map, offset, i);
}
