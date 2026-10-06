/*
** EPITECH PROJECT, 2022
** tools.c
** File description:
** tools functions
*/

#include "../include/my.h"
#include "../include/sokoban.h"

int is_locked(Game *g, Vect_2i v)
{
    char obstacles[] = "X#";

    return ((v.x != 0 && v.x != g->size.x - 1
    && v.y != 0 && v.y != g->size.y - 1
    && (contain(g->map[v.y - 1][v.x], obstacles)
    || contain(g->map[v.y + 1][v.x], obstacles))
    && (contain(g->map[v.y][v.x - 1], obstacles)
    || contain(g->map[v.y][v.x + 1], obstacles)))
    || ((v.y == 0 || v.y == g->size.y - 1)
    && (v.x == 0 || v.x == g->size.x - 1)));
}

int all_box_locked(Game *g)
{
    int nb = 0;

    for (int i = 0; i < g->size.x; i++)
        for (int j = 0; j < g->size.y; j++)
            nb += g->map[j][i] == 'X' && is_locked(g, (Vect_2i){i, j});
    return nb == g->nb_x;
}

int all_box_placed(Game *g)
{
    int nb = 0;

    for (int i = 0; g->str[i]; i++)
        nb += g->str[i] == 'O' && contain(g->map[i /
        (g->size.x + 1)][i % (g->size.x + 1)], "X");
    return nb == g->nb_o;
}

void mv_box(Game *g, Vect_2i v, int x, int y)
{
    g->map[v.y + y * 2][v.x + x * 2] = 'X';
    g->map[v.y + y][v.x + x] = !contain(g->str[
    (v.y + y) * (g->size.x + 1) + v.x + x], "X")
    ? g->str[(v.y + y) * (g->size.x + 1) + v.x + x] : ' ';
}

int check_box(Game *g, Vect_2i v, int x, int y)
{
    int state = g->map[v.y + y][v.x + x] == 'X'
    && v.y + y * 2 >= 0 && v.y + y * 2 < g->size.y
    && v.x + x * 2 >= 0 && v.x + x * 2 < g->size.x
    && contain(g->map[g->pos.y + y * 2][g->pos.x + x * 2], "O ");

    if (state)
        mv_box(g, v, x, y);
    return state;
}
