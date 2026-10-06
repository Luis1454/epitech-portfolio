/*
** EPITECH PROJECT, 2022
** deadend.c
** File description:
** what happen if it is a dead end
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void reset(solver_t *m)
{
    if (m->count > 2 && row(m) > 3) {
        m->pos_y = 0;
        m->pos_x = 0;
        m->i = 0;
        corner(m, m->len, m->line);
    }
}

int check_reset(solver_t *m)
{
    int count = 0;

    if (m->pos_x + 1 < m->len && m->map[m->pos_y][m->pos_x + 1] == 'o')
        count++;
    if (m->pos_y < m->line - 1 && m->map[m->pos_y + 1][m->pos_x] == 'o')
        count++;
    if (m->pos_x > 0 && m->map[m->pos_y][m->pos_x - 1] == 'o')
        count++;
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == 'o')
        count++;
    if (count > 3) {
        reset(m);
        return 0;
    }
    return 1;
}

int direction_dead(solver_t *m, int len, int line)
{
    if (m->pos_y < len - 1 && m->map[m->pos_y][m->pos_x + 1] == 'o') {
        m->map[m->pos_y][m->pos_x] = 'N';
        rightd(m, len);
        return 0;
    }
    if (m->pos_y < line - 1 && m->map[m->pos_y + 1][m->pos_x] == 'o') {
        m->map[m->pos_y][m->pos_x] = 'N';
        downd(m, line);
        return 0;
    }
    if (m->pos_x > 0 && m->map[m->pos_y][m->pos_x - 1] == 'o') {
        m->map[m->pos_y][m->pos_x] = 'N';
        leftd(m);
        return 0;
    }
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == 'o') {
        m->map[m->pos_y][m->pos_x] = 'N';
        upd(m);
        return 0;
    }
    return check_reset(m);
}
