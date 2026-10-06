/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** enemys
*/

#include "my_rpg.h"

void add_ennemys(game_t *game, ennemy_t *ennemy, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/textures/demon.png", NULL);

    ennemy->pos = pos;
    ennemy->life = 100;
    ennemy->attack = 10;
    ennemy->defense = 10;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.15, 0.15});
    sfSprite_setPosition(sprite, ennemy->pos);
    ennemy->sprite = sprite;
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void place_ennemys(game_t *game)
{
    if (game->ennemys_dead[0] == 0)
        add_ennemys(game, game->ennemy1, (sfVector2f){690, 430});
    if (game->ennemys_dead[1] == 0)
        add_ennemys(game, game->ennemy2, (sfVector2f){650, 530});
    if (game->ennemys_dead[2] == 0)
        add_ennemys(game, game->ennemy3, (sfVector2f){1010, 390});
}

void radar_ennemys(game_t *game)
{
    place_ennemys(game);
    if (((int)game->player->pos.x >= 3 && (int)game->player->pos.x <= 5) &&
        ((int)game->player->pos.y >= 16 && (int)game->player->pos.y <= 18)) {

    }
    if (((int)game->player->pos.x >= 1 && (int)game->player->pos.x <= 3) &&
        ((int)game->player->pos.y >= 13 && (int)game->player->pos.y <= 15)) {

    }
    if (((int)game->player->pos.x >= 4 && (int)game->player->pos.x <= 6) &&
        ((int)game->player->pos.y >= 8 && (int)game->player->pos.y <= 10)) {

    }
}
