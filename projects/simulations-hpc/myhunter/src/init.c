/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init functions
*/

#include "../include/my.h"
#include "../include/hunter.h"
#include "../include/my_macro_abs.h"

void reset_plane(Screen *s, int i)
{
    s->plane[i].vect.x = (rand() % 100) / 10 + 1;
    s->plane[i].vect.y = ((rand() % (int)
    (s->plane[i].vect.x * 100)) - s->plane[i].vect.x / 0.02) / 200;
    s->plane[i].model = rand() % 3;
    s->plane[i].pos = (sfVector2f){-64 * s->f, rand() % s->size.y * 0.75};
}

void init_plane(Screen *s, int nb)
{
    s->plane_sprite = sfSprite_create();
    sfSprite_setTexture(s->plane_sprite, s->plane_sheet, sfTrue);
    for (int i = 0; i < nb; i++)
        reset_plane(s, i);
}

void init_game(Screen *s)
{
    s->nb_plane = 10;
    s->f = 1.5;
    s->plane = malloc(sizeof(Plane) * s->nb_plane);
    s->plane_sheet = sfTexture_createFromFile("texture/plane.png", NULL);
    s->target_sprite = sfSprite_create();
    s->target_texture = sfTexture_createFromFile("texture/target.png", NULL);
    sfSprite_setTexture(s->target_sprite, s->target_texture, sfTrue);
    s->fixed = (sfVector2u){1920, 1080};
    s->size = s->fixed;
    s->mode.width = s->size.x;
    s->mode.height = s->size.y;
    s->mode.bitsPerPixel = 32;
    s->last_click_event = FALSE;
    s->board.start_score = 100;
    s->board.score = s->board.start_score;
    s->line = sfVertexArray_create();
    s->paused = FALSE;
    init_text(s);
}

void init_text(Screen *s)
{
    s->board.font = sfFont_createFromFile("fonts/nasa.otf");
    s->board.score_text = sfText_create();
    s->board.best_text = sfText_create();
    sfText_setColor(s->board.score_text, sfColor_fromRGB(255, 127, 0));
    sfText_setFont(s->board.score_text, s->board.font);
    sfText_setFont(s->board.best_text, s->board.font);
    sfText_setPosition(s->board.score_text, (sfVector2f){20, 10});
    compute_score(s);
}
