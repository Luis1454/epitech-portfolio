/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_resolution_screen.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void assign_resolution(game_t *game)
{
    sfVector2u size = {1920, 1080};
    if (game->resolution == 0)
        size = (sfVector2u){800, 600};
    if (game->resolution == 1)
        size = (sfVector2u){1024, 768};
    if (game->resolution == 2)
        size = (sfVector2u){1280, 720};
    if (game->resolution == 3)
        size = (sfVector2u){1920, 1080};
    sfRenderWindow_close(game->window);
    game->window = sfRenderWindow_create((sfVideoMode){size.x, size.y, 32},
    "My RPG", game->resolution == 4 ? sfFullscreen : sfDefaultStyle, NULL);
    game->size = (sfVector2i){size.x, size.y};
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

void sub_set_resolution(game_t *game)
{
    if (is_in_rect((sfIntRect){320, 0.3 * game->size.y - 35,
    200, 70}, game->mouse_pos) && sfMouse_isButtonPressed(sfMouseLeft)
    && !game->last) {
        game->resolution++;
        game->last = 1;
        assign_resolution(game);
    }
}

void set_resolution(game_t *game)
{
    char *sizes[] = {"800x600", "1024x768",
    "1280x720", "1920x1080", "Fullscreen", NULL};
    sfVector2u size = {800, 600};

    sfText_setColor(game->text, (sfColor){212, 193, 174, 255});
    add_text(game, game->text, "Resolution :",
    (sfVector2f){0.1 * game->size.x, 0.3 * game->size.y});
    add_rect(game, (sfVector2f){320, 0.3 * game->size.y - 35},
    (sfVector2f){200, 70}, (sfColor){212, 193, 174, 255});


    sfText_setColor(game->text, sfBlack);
    add_text(game, game->text, sizes[game->resolution],
    (sfVector2f){420, 0.3 * game->size.y});
    sfText_setColor(game->text, sfWhite);
    sub_set_resolution(game);
    game->last = game->event.type == sfEvtMouseButtonReleased ? 0 : game->last;
    game->resolution = (game->resolution < 5 ? game->resolution : 0);
    size = sfRenderWindow_getSize(game->window);
    game->size = (sfVector2i){size.x, size.y};
}
