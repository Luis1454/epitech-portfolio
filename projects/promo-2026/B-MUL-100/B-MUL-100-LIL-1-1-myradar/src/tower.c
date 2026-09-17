/*
** EPITECH PROJECT, 2021
** towers.c
** File description:
** functions for towers
*/

#include "../includes/include.h"
#include "../includes/my.h"

int get_T_text(sfRenderWindow *window, sfText *text, Tower tower)
{
    sfText_setPosition(text, (sfVector2f) {tower.X + 7, tower.Y - 1});
    sfText_setString(text, tower.plate);
    sfText_setColor(text, sfGreen);
    sfText_setCharacterSize(text, 11);
    sfRenderWindow_drawText(window, text, NULL);
    return 1;
}

int get_T_radius_label(sfRenderWindow *w, sfText *text, Tower tower, int off)
{
    char *unit = "nm";
    char val[10];
    int nm = 0;
    int l = 0;

    nm = tower.radius * 0.54;
    my_nbr_to_str(nm, val);
    while ('0' <= val[l] && val[l] <= '9')
        l++;
    my_strcat(val, " ");
    my_strncat(val, unit, l + 2);
    val[l + 3] = 0;
    sfText_setString(text, val);
    sfText_setPosition(text, (sfVector2f)
    {tower.X + off * 0.71 + 8, tower.Y - off * 0.71 - 8});
    sfRenderWindow_drawText(w, text, NULL);
    return 1;
}

int get_T_circle(sfRenderWindow *w, sfCircleShape *circle,
Tower tower, int off)
{
    sfCircleShape_setRadius(circle, off);
    sfCircleShape_setPosition(circle, (sfVector2f)
    {tower.X - off, tower.Y - off});
    sfRenderWindow_drawCircleShape(w, circle, NULL);
    return 1;
}

void tower_loop(Screen *s, Stat *st, Tower towers[])
{
    for (int i = 0; i < st->nbTowers; i++) {
        s->off = towers[i].radius * s->Xsize / 50000;
        sfSprite_setPosition(s->twr_sprite,
        (sfVector2f) {towers[i].X - 10, towers[i].Y - 10});
        sfRenderWindow_drawSprite(s->window, s->twr_sprite, NULL);
        get_T_text(s->window, s->text, towers[i]);
        get_T_radius_label(s->window, s->text, towers[i], s->off);
        get_T_circle(s->window, s->circle, towers[i], s->off);
    }
    sfTexture_updateFromPixels(s->trace, (sfUint8*) s->pixels,
    s->Xsize, s->Ysize, 0, 0);
    sfRenderWindow_drawSprite(s->window, s->traceMap, NULL);
    sfRenderWindow_display(s->window);
}
