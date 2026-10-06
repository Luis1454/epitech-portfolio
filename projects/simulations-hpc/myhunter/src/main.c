/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/hunter.h"
#include "../include/my_macro_abs.h"

void sub_game_loop(Screen *s)
{
    compute_score(s);
    while (sfRenderWindow_pollEvent(s->window, &s->event))
        s->event.type == sfEvtClosed ? sfRenderWindow_close(s->window) : 0;
    s->size = sfRenderWindow_getSize(s->window);
    compute_line(s);
    sfRenderWindow_drawSprite(s->window, s->sprite, NULL);
    s->paused = sfKeyboard_isKeyPressed(sfKeyDelete) ? !s->paused : s->paused;
    plane_loop(s);
    compute_target(s);
    if (sfMouse_isButtonPressed(0))
        sfRenderWindow_drawVertexArray(s->window, s->line, NULL);
    sfRenderWindow_drawText(s->window, s->board.score_text, NULL);
    sfRenderWindow_display(s->window);
    s->last_click_event *= sfMouse_isButtonPressed(0);
    if (s->board.score > s->board.best) {
        save_score(s);
        s->board.best = s->board.score;
    }
}

void game_loop(Screen *s)
{
    s->clock = sfClock_create();
    sfVertexArray_setPrimitiveType(s->line, sfTriangles);
    sfSprite_setTexture(s->sprite, s->texture, TRUE);
    while (sfRenderWindow_isOpen(s->window) && s->board.score > 0
    && !sfKeyboard_isKeyPressed(sfKeyEscape))
        sub_game_loop(s);
}

void save_score(Screen *s)
{
    int fd = open("best_score", O_WRONLY | O_TRUNC);
    char *tmp = malloc(sizeof(char) * 10);

    if (fd != -1) {
        my_put_nbr_to_fd(s->board.score - s->board.start_score,
        __INT_MAX__, fd);
        close(fd);
    }
    free(tmp);
}

int show_usage(const char *arg)
{
    if (!are_equals(arg, "-h"))
        return 84;
    my_putstr("USAGE:\n    ./my_hunter [-h]\n\n");
    my_putstr("DESCRIPTION:\n    Protect the valley from enemy planes, ");
    my_putstr("if they manage\n    to pass your vigilance, ");
    my_putstr("it could be the endgame !\n\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc > 2)
        return 84;
    if (argc == 2)
        return show_usage(argv[1]);
    srand(time(NULL));
    Screen *s = malloc(sizeof(Screen));
    init_game(s);
    init_plane(s, s->nb_plane);
    s->window = sfRenderWindow_create(s->mode, "skywar hunter",
    sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(s->window, sfFalse);
    sfRenderWindow_setFramerateLimit(s->window, FRAMERATE);
    s->sprite = sfSprite_create();
    sfSprite_setScale(s->target_sprite, (sfVector2f){0.1, 0.1});
    s->texture = sfTexture_createFromFile("texture/background.png", NULL);
    sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    game_loop(s);
    sfRenderWindow_destroy(s->window);
    free(s);
    return 0;
}
