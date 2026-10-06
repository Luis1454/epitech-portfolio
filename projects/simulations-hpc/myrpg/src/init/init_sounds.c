/*
** EPITECH PROJECT, 2023
** sound.c
** File description:
** sound handling
*/

#include "../../include/my.h"
#include "../../include/my_rpg.h"
#include <stdio.h>

sound_t *init_sounds(sound_t *sounds)
{
    sounds = malloc(sizeof(sound_t));
    if (sounds == NULL)
        return NULL;
    sounds->music_vol = 0;
    sounds->sound_vol = 50;
    sounds->music = sfMusic_createFromFile("assets/sounds/menu.ogg");
    sounds->click = sfSound_create();
    sounds->click_buffer = sfSoundBuffer_createFromFile
    ("assets/sounds/click.ogg");
    sfMusic_setLoop(sounds->music, sfTrue);
    sfMusic_setVolume(sounds->music, sounds->music_vol);
    sfMusic_play(sounds->music);
    sfSound_setBuffer(sounds->click, sounds->click_buffer);
    if (sounds->click == NULL)
        return NULL;
    if (sounds->click_buffer == NULL)
        return NULL;
    sfSound_setVolume(sounds->click, sounds->sound_vol);
    return sounds;
}

void music_vol(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        if (game->sounds->music_vol < 100) {
            game->sounds->music_vol += 1.0;
            sfMusic_setVolume(game->sounds->music, game->sounds->music_vol);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        if (game->sounds->music_vol > 0) {
            game->sounds->music_vol -= 1.0;
            sfMusic_setVolume(game->sounds->music, game->sounds->music_vol);
        }
    }
}

void sound_vol(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        if (game->sounds->sound_vol < 100) {
            game->sounds->sound_vol += 1.0;
            sfSound_setVolume(game->sounds->click, game->sounds->sound_vol);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        if (game->sounds->sound_vol > 0) {
            game->sounds->sound_vol -= 1.0;
            sfSound_setVolume(game->sounds->click, game->sounds->sound_vol);
        }
    }
}

void change_volume(game_t *game)
{
    add_text(game, game->text, "music volume:", (sfVector2f){1660, 20});
    add_text(game, game->text, my_ftoa(game->sounds->music_vol),
    (sfVector2f){1850, 20});

    add_text(game, game->text, "sound volume:", (sfVector2f){1650, 55});
    add_text(game, game->text, my_ftoa(game->sounds->sound_vol),
    (sfVector2f){1850, 55});

    music_vol(game);
    sound_vol(game);
}
