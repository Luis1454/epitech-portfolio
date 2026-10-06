/*
** EPITECH PROJECT, 2023
** text.c
** File description:
** text functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

void display_text(screen_t *s, char *str, sfVector2f pos, sfColor color)
{
    sfVector2f position;
    sfVector2f origin;
    sfFloatRect rect;

    sfText_setString(s->text, str);
    sfText_setCharacterSize(s->text, 14);

    rect = sfText_getGlobalBounds(s->text);

    origin = (sfVector2f){rect.width / 2.0, rect.height / 2.0};
    sfText_setOrigin(s->text, origin);
    position = (sfVector2f){pos.x + origin.x, pos.y + origin.y};
    sfText_setPosition(s->text, position);
    sfText_setStyle(s->text, 0);
    sfText_setColor(s->text, color);
    sfRenderWindow_drawText(s->window, s->text, NULL);
}
