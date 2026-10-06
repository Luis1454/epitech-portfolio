/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** loop_window.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

void sub_loop_window(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfSprite_setTexture(game->texture->sprite, game->texture->t[0],
    sfTrue);
    sfRenderWindow_drawSprite(game->window, game->texture->sprite, NULL);
    button_handling(game, "New game", "New game");
    button_handling(game, "About", "About");
    button_handling(game, "Settings", "Settings");
    button_handling(game, "Open map", "Open map");
    display_game(game);
    change_volume(game);
    if (game->fade < 1.0 - game->fade_speed)
        add_rect(game, (sfVector2f){0, 0},
        (sfVector2f){game->size.x, game->size.y},
        (sfColor){0, 63 * game->fade, 127 * game->fade,
        255 - (int)(255 * (game->fade += game->fade_speed))});

    sfRenderWindow_display(game->window);
}

void init_dead_ennemys(game_t *game)
{
    game->ennemys_dead = malloc(sizeof(int) * 4);
    game->ennemys_dead[0] = 0;
    game->ennemys_dead[1] = 0;
    game->ennemys_dead[2] = 0;
    game->ennemys_dead[3] = 0;
}

void loop_wimdow(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    game->size = (sfVector2i){size.x, size.y};
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->menu_id == get_id_by_menu_name(game->menu, "Start") &&
        is_in_rect(get_buttons_by_name(get_menu_by_name(game->menu,
        "Start")->buttons, "Quit")->rect, game->mouse_pos)
        && game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->sounds->click);
            game->is_started = 0;
        }
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyEscape)
            game->menu_id = get_id_by_menu_name(game->menu, "Start");
    }
    sub_loop_window(game);
}
    // init_dead_ennemys(game);
