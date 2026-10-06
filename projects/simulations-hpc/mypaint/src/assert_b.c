/*
** EPITECH PROJECT, 2022
** assert_b.c
** File description:
** assertion functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int is_in_box(frame_t box, sfVector2f point)
{
    return (box.a.x < point.x && point.x < box.a.x + box.b.x
    && box.a.y < point.y && point.y < box.a.y + box.b.y);
}

int is_in_circle(sfVector2f center, sfVector2f point, double radius)
{
    return (get_pythagore(center, point) <= radius);
}

int start_by(char *str, char *start)
{
    int i = 0;

    if (!str || !start)
        return 0;
    for (; str[i] && start[i] && str[i] == start[i]; i++);
    return i == my_strlen(start);
}

int check_childs_box(button_t *b, sfVector2f pos)
{
    for (button_t *c = b; c; c = c->child)
        if (is_in_box(c->box, pos))
            return 1;
    return 0;
}
