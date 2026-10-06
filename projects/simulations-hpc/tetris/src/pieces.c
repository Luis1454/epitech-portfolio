/*
** EPITECH PROJECT, 2022
** pieces.c
** File description:
** pieces file
*/

#include "../includes/my.h"
#include "../includes/tetris.h"

int get_next_num(Game *g, char *str, int i)
{
    for (; !('0' <= str[i] && str[i] <= '9') && str[i] && str[i] != '\n'; i++);
    if (my_strlen(str) == i)
        return 0;

    g->i = i + 1;
    return str[i] - 48;
}

void init_map(Game *g)
{
    g->pieces[g->nb_pieces].shape = malloc(sizeof(int *) *
    (g->pieces[g->nb_pieces].size.y + 1));
    for (int i = 0; i < g->pieces[g->nb_pieces].size.y; i++)
        g->pieces[g->nb_pieces].shape[i] = malloc(sizeof(int) *
        (g->pieces[g->nb_pieces].size.x + 1));
}

void sub_get_map(Game *g, char *raw, int i)
{
    for (int j = 0; j < g->pieces[g->nb_pieces].size.x + 1; j++) {
        g->pieces[g->nb_pieces].shape[i][j] = contain(raw[g->i], "*");
        g->i++;
        if (raw[g->i] == '\n') {
            g->i++;
            break;
        }
    }
}

char **get_map(Game *g, char *raw)
{
    for (g->i = 1; raw[g->i - 1] != '\n'; g->i++);
    for (int i = 0; i < g->pieces[g->nb_pieces].size.y; i++)
        sub_get_map(g, raw, i);
}

int get_piece(Game *g, char *raw)
{
    g->i = 0;
    g->pieces[g->nb_pieces].size.x = get_next_num(g, raw, g->i);
    g->pieces[g->nb_pieces].size.y = get_next_num(g, raw, g->i);
    g->pieces[g->nb_pieces].color = get_next_num(g, raw, g->i);
    init_map(g);

    get_map(g, raw);

    g->is_fake[g->nb_pieces] = g->pieces[g->nb_pieces].color <= 0
    || g->pieces[g->nb_pieces].size.x <= 0
    || g->pieces[g->nb_pieces].size.y <= 0;

    g->nb_pieces++;
    return g->is_fake[g->nb_pieces - 1];
}
