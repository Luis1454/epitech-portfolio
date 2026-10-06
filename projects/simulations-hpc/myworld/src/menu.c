/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu
*/

#include "../includes/my_world.h"

void button(Screen *s, sfEvent event)
{
    if ((s->font->a_x < s->mouse_pos.y
    && s->mouse_pos.y < s->font->a_x * 2.2)
    && (s->font->a_y -5 < s->mouse_pos.x
    && s->mouse_pos.x < s->font->a_y * 6)) {
        s->font->menu_tex++;
        if (s->font->menu_tex > 2)
            s->font->menu_tex = 0;
    }
    if ((s->font->a_x * 3 < s->mouse_pos.y
    && s->mouse_pos.y < s->font->a_x * 4.5) && (s->font->a_y < s->mouse_pos.x
    && s->mouse_pos.x < s->font->a_y * 5)) {
        s->font->brush_tex++;
        if (s->font->brush_tex > 9)
            s->font->brush_tex = 0;
    }
}

int text(Screen *s)
{
    if (!s->font->font)
        return 84;
    sfText_setString(s->font->text, s->font->menu_text[s->font->menu_tex]);
    sfRenderWindow_drawText(s->window, s->font->text, NULL);
    sfText_setString(s->font->box, s->font->brush_text[s->font->brush_tex]);
    sfRenderWindow_drawText(s->window, s->font->box, NULL);
    sfText_setString(s->font->box_bis,
    s->font->winsize_text[s->font->win_tex]);
    sfRenderWindow_drawText(s->window, s->font->box_bis, NULL);
}

void destroy_font(Screen *s)
{
    sfText_destroy(s->font->text);
    sfText_destroy(s->font->box);
    sfText_destroy(s->font->box_bis);
    sfFont_destroy(s->font->font);
}
