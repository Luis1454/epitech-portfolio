/*
** EPITECH PROJECT, 2022
** solver.c
** File description:
** solve maze
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void print_map(solver_t *m, int j)
{
    for (int i = 0; m->map[j][i] != '\0'; i++) {
        if (m->map[j][i] == 'N') {
            my_putchar('*');
        } else {
            my_putchar(m->map[j][i]);
        }
    }
    my_putchar('\n');
}

int end(solver_t *m, int len , int line)
{
    if (m->pos_x == len - 1 && m->pos_y == line - 1) {
        m->map[m->pos_y][m->pos_x] = 'o';
        return 0;
    }
    return 1;
}

void explorer(solver_t *m)
{
    m->pos_y = 0;
    m->pos_x = 0;
    m->i = 0;
    int len = my_strlen(m->map[0]);
    int line = nbr_l(m->map);
    m->len = len;
    m->line = line;
    m->map[0][0] = 'o';

    corner(m, len, line);
    while (1) {
        if (end(m, len, line) == 0)
            break;
        if (m->pos_y > 0 || m->pos_y < line - 1
        || m->pos_x > 0 || m->pos_x < len - 1) {
            direction(m, len, line);
        }
        if (m->pos_x != len || m->pos_y != line - 1)
            cross(m);
        core_block(m, len, line);
    }
}

int solver(solver_t *p)
{
    p->map = map_2darr(p->path);
    explorer(p);
    if (end(p, p->len, p->line) == 1) {
        my_putstr("no solution found\n");
        return 84;
    } else {
        for (int i = 0; i < nbr_l(p->map); i++) {
            print_map(p, i);
        }
        return 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    solver_t *p = malloc(sizeof(solver_t));
    p->path = av[1];
    if (ac < 2) {
        return 84;
    }
    solver(p);
}
