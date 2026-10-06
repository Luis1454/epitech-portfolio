/*
** EPITECH PROJECT, 2022
** move_deadd.c
** File description:
** move in dead end
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void upd(solver_t *m)
{
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == 'o') {
        m->pos_y--;
    }
}

void leftd(solver_t *m)
{
    if (m->pos_x > 0 && m->map[m->pos_y][m->pos_x - 1] == 'o') {
        m->pos_x--;
    }
}

void rightd(solver_t *m, int len)
{
    if (m->map[m->pos_y][m->pos_x + 1] == 'o' && m->pos_x < len - 1) {
        m->pos_x++;
    }
}

void downd(solver_t *m, int line)
{
    if (m->map[m->pos_y + 1][m->pos_x] == 'o' && m->pos_y < line - 1) {
        m->pos_y++;
    }
}
