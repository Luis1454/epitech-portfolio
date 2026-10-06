/*
** EPITECH PROJECT, 2022
** border.c
** File description:
** func on border
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void corner(solver_t *m,int len, int line)
{
    if ((m->pos_x == 0 && m->pos_y == 0)
    && ((m->map[m->pos_y + 1][m->pos_x] == '*')
    || (m->map[m->pos_y][m->pos_x + 1] == '*'))) {
        m->map[m->pos_y][m->pos_x] = 'o';
        right(m, len);
        down(m, line);
    }
}

void core_block(solver_t *m, int len, int line)
{
    int count = 0;

    if (m->pos_x + 1 < len && m->map[m->pos_y][m->pos_x + 1] == 'X')
        count++;
    if (m->pos_y < line - 1 && m->map[m->pos_y + 1][m->pos_x] == 'X')
        count++;
    if (m->pos_x > 0 && m->map[m->pos_y][m->pos_x - 1] == 'X')
        count++;
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == 'X')
        count++;
    if (count > 2) {
        while (m->pos_x != m->sav_x && m->pos_y && m->sav_y)
            direction_dead(m, m->len, m->line);
    }
    check_reset(m);
    m->count = count;
}
