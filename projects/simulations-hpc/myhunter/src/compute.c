/*
** EPITECH PROJECT, 2022
** compute.c
** File description:
** engine functions
*/

#include "../include/my.h"
#include "../include/hunter.h"
#include "../include/my_macro_abs.h"

void compute_score(Screen *s)
{
    sfText_setScale(s->board.score_text,  (sfVector2f)
    {(double)s->fixed.x / s->size.x, (double)s->fixed.y / s->size.y});
    char text[25] = "score : ";
    char *tmp = malloc(sizeof(char) * 10);
    my_strcat(text, my_itoa(s->board.score, tmp));
    sfText_setString(s->board.score_text, text);
    free(tmp);
}

void compute_line(Screen *s)
{
    sfVertex v;
    v.color = sfRed;

    sfVertexArray_clear(s->line);
    v.color = sfColor_fromRGB(255, 127, 127);
    v.position = (sfVector2f){s->size.x * 0.83, s->size.y * 1.1};
    v.position = (sfVector2f){v.position.x * s->fixed.x /
    s->size.x, v.position.y * s->fixed.y / s->size.y};
    sfVertexArray_append(s->line, v);
    v.position = (sfVector2f){s->size.x * 0.8, s->size.y * 1.1};
    v.position = (sfVector2f){v.position.x * s->fixed.x /
    s->size.x, v.position.y * s->fixed.y / s->size.y};
    sfVertexArray_append(s->line, v);
    v.position = (sfVector2f){s->mouse.x, s->mouse.y};
    v.color = sfRed;
    sfVertexArray_append(s->line, v);
    s->mouse = sfMouse_getPositionRenderWindow(s->window);
    s->mouse = (sfVector2i){s->mouse.x * s->fixed.x /
    s->size.x, s->mouse.y * s->fixed.y / s->size.y};
}

void compute_target(Screen *s)
{
    sfSprite_setScale(s->target_sprite, (sfVector2f)
    {0.1 * s->fixed.x / s->size.x, 0.1 * s->fixed.y / s->size.y});
    sfSprite_setPosition(s->target_sprite, (sfVector2f){s->mouse.x
    - sfSprite_getGlobalBounds(s->target_sprite).width / 2, s->mouse.y
    - sfSprite_getGlobalBounds(s->target_sprite).height / 2});
    sfRenderWindow_drawSprite(s->window, s->target_sprite, NULL);
}

int is_in_box(sfVector2i mouse, sfVector2f pos, int width, int height)
{
    return mouse.y >= pos.y && mouse.x >= pos.x
    && mouse.y <= pos.y + height && mouse.x <= pos.x + width;
}
