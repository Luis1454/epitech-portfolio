/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_settings.c
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"

void sub_display_settings(game_t *game)
{
    display_vslider(game, (sfFloatRect){game->size.x / 2 - 100,
    game->size.y / 2 + 75, 20, -150}, (sfColor){102, 86, 72, 255},
    game->sounds->music_vol / 100.0);
    display_vslider(game, (sfFloatRect){game->size.x / 2 + 400,
    game->size.y / 2 + 70, 20, -150}, (sfColor){102, 86, 72, 255},
    game->sounds->sound_vol / 100.0);
}

int display_settings(game_t *game)
{
    add_rect(game, (sfVector2f){0, 0},
    (sfVector2f){game->size.x, game->size.y}, (sfColor){0, 0, 0, 168});
    set_resolution(game);
    sfText_setCharacterSize(game->text, 24);
    add_text(game, game->text, "Music volume",
    (sfVector2f){game->size.x / 2 - 100, game->size.y / 2 - 150});
    add_text(game, game->text, "Sound volume",
    (sfVector2f){game->size.x / 2 + 400, game->size.y / 2 - 150});
    add_text(game, game->text, "pressed P to increase the music volume",
    (sfVector2f){game->size.x / 2 - 100, game->size.y / 2 + 100});
    add_text(game, game->text, "pressed M to decrease the music volume",
    (sfVector2f){game->size.x / 2 - 100, game->size.y / 2 + 150});
    add_text(game, game->text, "pressed O to increase the sound volume",
    (sfVector2f){game->size.x / 2 + 400, game->size.y / 2 + 100});
    add_text(game, game->text, "pressed L to decrease the sound volume",
    (sfVector2f){game->size.x / 2 + 400, game->size.y / 2 + 150});
    sub_display_settings(game);
    sfText_setCharacterSize(game->text, 45);
    return 0;
}
