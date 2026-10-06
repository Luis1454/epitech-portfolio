/*
** EPITECH PROJECT, 2022
** move.C
** File description:
** movement
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void up(solver_t *m)
{
    if (m->pos_y > 0 && (m->map[m->pos_y - 1][m->pos_x] == '*'
    || m->map[m->pos_y - 1][m->pos_x] == 'o')) {
        m->map[m->pos_y - 1][m->pos_x] = 'o';
        m->pos_y--;
    }
}

void left(solver_t *m)
{
    if (m->pos_x > 0 && ((m->map[m->pos_y][m->pos_x - 1] == '*')
    || (m->map[m->pos_y][m->pos_x - 1] == 'o'))) {
        m->map[m->pos_y][m->pos_x - 1] = 'o';
        m->pos_x--;
    }
}

void right(solver_t *m, int len)
{
    if (m->pos_x < len - 1 && ((m->map[m->pos_y][m->pos_x + 1] == '*')
    || (m->map[m->pos_y][m->pos_x + 1] == 'o'))) {
        m->map[m->pos_y][m->pos_x + 1] = 'o';
        m->pos_x++;
    }
}

void down(solver_t *m, int line)
{
    if (m->pos_y < line && ((m->map[m->pos_y + 1][m->pos_x] == '*')
    || (m->map[m->pos_y + 1][m->pos_x] == 'o'))) {
        m->map[m->pos_y + 1][m->pos_x] = 'o';
        m->pos_y++;
    }
}
