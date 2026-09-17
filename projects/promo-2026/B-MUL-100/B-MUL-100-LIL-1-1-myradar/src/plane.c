/*
** EPITECH PROJECT, 2021
** plane.c
** File description:
** functions for planes
*/

#include "../includes/include.h"

int get_P_len(int len, Plane planes[len])
{
    int i = 0;

    while (planes[i].id)
        i++;
    return i;
}

int get_collide(int len, int l, Plane plane, Plane p[len])
{
    for (int i = 0; i < len; i++) {
        if ((((plane.X <= p[i].X && p[i].X <= plane.X + l)
        || (plane.X < p[i].X + l && p[i].X + l < plane.X + l))
        && ((plane.Y <= p[i].Y && p[i].Y <= plane.Y + l)
        || (plane.Y < p[i].Y + l && p[i].Y + l < plane.Y + l)))
        && p[i].id != plane.id)
            return 1;
    }
    return 0;
}

void plane_loop_A(Screen *s, Stat *st, Plane planes[], Tower towers[])
{
    planes[st->i].X += ((double) planes[st->i].Xspeed) / 300;
    planes[st->i].Y += ((double) planes[st->i].Yspeed) / 300;

    if (planes[st->i].X < 0)
        planes[st->i].X = s->Xsize - 1;
    if (planes[st->i].Y < 0)
        planes[st->i].Y = s->Ysize - 11;

    if (planes[st->i].X > s->Xsize - 1)
        planes[st->i].X = 0;
    if (planes[st->i].Y > s->Ysize - 11)
        planes[st->i].Y = 0;
    sfRectangleShape_setOutlineColor(s->rect, get_color(is_in_circle(
    st->nbTowers, s->Xsize, planes[st->i], towers)));
    if (!is_in_circle(st->nbPlanes, s->Xsize, planes[st->i], towers)) {
        get_warning(st->nbPlanes, s->rect, planes[st->i], planes);
        if (get_collide(st->nbPlanes, 20, planes[st->i], planes))
            sfRenderWindow_close(s->window);
    }
}

void plane_loop_B(Screen *s, Stat *st, Plane planes[], Tower towers[])
{
    s->pixels[((int) planes[st->i].Y + 10) * s->Xsize + ((int)
    planes[st->i].X + 10)] = sfRectangleShape_getOutlineColor(s->rect);
    sfSprite_setPosition(s->pln_sprite, (sfVector2f)
    {planes[st->i].X, planes[st->i].Y});
    sfRenderWindow_drawSprite(s->window, s->pln_sprite, NULL);
    sfText_setColor(s->text, get_color(is_in_circle(st->nbTowers, s->Xsize,
    planes[st->i], towers)));
    sfText_setPosition(s->text, (sfVector2f) {planes[st->i].X + 26,
    planes[st->i].Y + 4});
    sfText_setString(s->text, planes[st->i].name);
    sfText_setCharacterSize(s->text, 15);
    sfRenderWindow_drawText(s->window, s->text, NULL);
    sfRectangleShape_setPosition(s->rect, (sfVector2f)
    {planes[st->i].X, planes[st->i].Y});
    sfRenderWindow_drawRectangleShape(s->window, s->rect, NULL);
}
