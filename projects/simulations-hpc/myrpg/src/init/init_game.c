/*
** EPITECH PROJECT, 2023
** init_game.c
** File description:
** init the game memory
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

int game_loop(game_t *game)
{
    game->is_started = 1;
    game->texture->sprite = sfSprite_create();
    sfSprite_setTexture(game->item_sprite, game->texture->items, sfTrue);
    while (sfRenderWindow_isOpen(game->window) && game->is_started) {
        loop_wimdow(game);
    }
    sfClock_destroy(game->clock);
    sfMusic_destroy(game->sounds->music);
    sfSound_destroy(game->sounds->click);
    sfSoundBuffer_destroy(game->sounds->click_buffer);
    sfRenderWindow_destroy(game->window);
    return 0;
}

int init_window(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){game->size.x,
    game->size.y, 32}, "Bad guy RPG", sfClose | sfResize, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->clock = sfClock_create();
    if (!game->clock || init_texture(game)
    || init_menu(game) || init_player(game))
        return 84;
    return game_loop(game);
}

void init_ennemys(game_t *game)
{
    game->ennemy1 = malloc(sizeof(ennemy_t));
    game->ennemy2 = malloc(sizeof(ennemy_t));
    game->ennemy3 = malloc(sizeof(ennemy_t));
}

void sub_init_game_map(game_t *game)
{
    game->path = malloc(sizeof(char) * 2048);
    game->path = my_memset(game->path, 0, 2048);
    game->file = malloc(sizeof(char) * 2048);
    game->file = my_memset(game->file, 0, 2048);
    game->file = my_strcpy(game->file, "maps/map.txt");
    game->path = my_strcpy(game->path, "/");
    game->map = malloc(sizeof(map_t));
    game->map->sprite = sfSprite_create();
    game->map->f = 0;
    game->fade = 0;
    game->fade_speed = 1.0 / (60.0 * 3.0);
    game->resolution = 3;
    game->map->rescale = 1.25;
    game->map->zoom_speed = 0.1;
}

int init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return 84;
    game->size = (sfVector2i){1920, 1080};
    game->rect = sfRectangleShape_create();
    game->item_sprite = sfSprite_create();
    game->sounds = init_sounds(game->sounds);
    game->items = malloc(sizeof(item_t *));
    init_ennemys(game);
    init_items(game);
    init_text(game);
    sub_init_game_map(game);
    if (load_map("maps/map.txt", game->map))
        return 84;
    return init_window(game);
}
