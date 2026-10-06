/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** player functions
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

static void sub_init_player(game_t *g)
{
    g->player->reverse = 1;
    g->player->max_life = 100;
    g->player->life = 100;
    g->player->max_mana = 100;
    g->player->mana = 20;
    g->player->speed = 5;
    g->player->sprite_offset = 0;
    g->player->walk_loop = 0;
}

int init_player(game_t *g)
{
    g->player = malloc(sizeof(player_t));
    if (!g->player)
        return 84;
    sub_init_player(g);
    g->player->pos = (sfVector2f){g->map->size.x / 2,
    g->map->size.y / 2};
    g->player->rect = (sfIntRect){0, 0, 16, 48};
    g->player->scale = (sfVector2f){2, 2};
    g->player->is_inventory = 0;
    g->texture->players = sfTexture_createFromFile
    ("assets/textures/player.png", NULL);
    g->player->sprite = sfSprite_create();
    sfSprite_setTexture(g->player->sprite, g->texture->players, sfTrue);
    sfSprite_setTextureRect(g->player->sprite, g->player->rect);
    sfSprite_setPosition(g->player->sprite, g->player->pos);
    init_inventory(g->player);
    return 0;
}

void handle_animation(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyQ)
    || sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight)
    || sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (!(g->player->walk_loop % (g->player->speed))) {
            g->player->sprite_offset += 22;
            g->player->sprite_offset %= 88;
            g->player->walk_loop = 0;
        }
        sfSprite_setTextureRect(g->player->sprite,
        (sfIntRect) {g->player->rect.left + g->player->sprite_offset,
        g->player->rect.top, g->player->rect.width, g->player->rect.height});
        g->player->walk_loop++;
    } else {
        g->player->sprite_offset = 0;
        sfSprite_setTextureRect(g->player->sprite,
        (sfIntRect) {g->player->rect.left, g->player->rect.top,
        g->player->rect.width, g->player->rect.height});
    }
}

void display_player(game_t *g)
{
    sfVector2i pos = id_to_iso((int)g->player->pos.y *
    g->map->size.x + (int)g->player->pos.x,
    g->map->size, g->map->origin, g->map->rescale);

    sfSprite_setOrigin(g->player->sprite, (sfVector2f){11, 0});
    sfSprite_setPosition(g->player->sprite, (sfVector2f){pos.x, pos.y - 32 *
    g->map->rescale * (get_pos_alt(g, (sfVector2i){g->player->pos.x,
    g->player->pos.y}) + 1)});
    sfRenderWindow_drawSprite(g->window, g->player->sprite, NULL);
}
