/*
** EPITECH PROJECT, 2022
** check.C
** File description:
** check around pos
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

int redirection(solver_t *m, int len, int line)
{
    if (m->pos_x < len - 1 && m->map[m->pos_y][m->pos_x + 1] == 'o') {
        right(m, len);
        return 0;
    }
    if (m->pos_y < line - 1 && (m->map[m->pos_y][m->pos_x + 1] == 'o')) {
        down(m, line);
        return 0;
    }
    if (m->pos_x > 0 && (m->map[m->pos_y][m->pos_x + 1] == 'o')) {
        left(m);
        return 0;
    }
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == 'o') {
        up(m);
        return 0;
    }
    if (end(m, len, line) == 0)
        return 0;
    return 1;
}

int direction(solver_t *m, int len, int line)
{
    if (m->pos_x < len - 1 && m->map[m->pos_y][m->pos_x + 1] == '*') {
        right(m, len);
        return 0;
    }
    if (m->pos_y < line - 1 && m->map[m->pos_y + 1][m->pos_x] == '*') {
        down(m, line);
        return 0;
    }
    if (m->pos_x > 0 && m->map[m->pos_y][m->pos_x - 1] == '*') {
        left(m);
        return 0;
    }
    if (m->pos_y > 0 && m->map[m->pos_y - 1][m->pos_x] == '*') {
        up(m);
        return 0;
    }
    redirection(m, len, line);
    if (end(m, len, line) == 0)
        return 0;
    return 1;
}

int row(solver_t *m)
{
    m->i++;
    return m->i;
}

int sub_cross(solver_t *m)
{
    if (m->pos_y > 0 && m->pos_x < m->len
        && (m->map[m->pos_y - 1][m->pos_x] == '*')
        && (m->map[m->pos_y][m->pos_x + 1] == '*')) {
        m->sav_x = m->pos_x;
        m->sav_y = m->pos_y;
        return 0;
    }
    if (m->pos_x > 0 && m->pos_y > 0 && (m->map[m->pos_y - 1][m->pos_x] == '*')
        && (m->map[m->pos_y][m->pos_x - 1] == '*')) {
        m->sav_x = m->pos_x;
        m->sav_y = m->pos_y;
        return 0;
    }
    return 1;
}

int cross(solver_t *m)
{
    if (m->pos_x < m->len && m->pos_y < m->line - 1
        && (m->map[m->pos_y + 1][m->pos_x] == '*')
        && (m->map[m->pos_y][m->pos_x + 1] == '*')) {
        m->sav_x = m->pos_x;
        m->sav_y = m->pos_y;
        return 0;
    }
    if (m->pos_x > 0 && m->pos_y < m->line - 1
        && (m->map[m->pos_y + 1][m->pos_x] == '*')
        && (m->map[m->pos_y][m->pos_x - 1] == '*')) {
        m->sav_x = m->pos_x;
        m->sav_y = m->pos_y;
        return 0;
    }
    return sub_cross(m);
}
