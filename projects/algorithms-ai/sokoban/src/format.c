/*
** EPITECH PROJECT, 2022
** format.c
** File description:
** format functions
*/

#include "../include/my.h"
#include "../include/sokoban.h"

void format_map(Game *g)
{
    char *tmp = malloc(sizeof(char) * ((g->size.y + 1) * (g->size.x + 1) + 1));
    int j = 0;
    int n = 0;
    int l = 0;

    for (int i = 0; g->str[i]; i++, j++, n++) {
        for (int k = 0; g->str[i] == '\n' &&
        k < g->size.x - n - !l + 1; j++, k++) {
            tmp[j] = ' ';
        }
        l += g->str[i] == '\n';
        n *= g->str[i] != '\n';
        tmp[j] = g->str[i];
    }
    tmp[j] = 0;
    free(g->str);
    g->str = tmp;
}

void get_move(Game *g)
{
    Vect_2i v = g->pos;

    g->pos.y -= g->key == KEY_UP && v.y > 0
    && (contain(g->map[v.y - 1][v.x], "O ") || check_box(g, v, 0, -1));
    g->pos.y += g->key == KEY_DOWN && v.y < g->size.y - 1
    && (contain(g->map[v.y + 1][v.x], "O ") || check_box(g, v, 0, 1));
    g->pos.x -= g->key == KEY_LEFT && v.x > 0
    && (contain(g->map[v.y][v.x - 1], "O ") || check_box(g, v, -1, 0));
    g->pos.x += g->key == KEY_RIGHT && v.x < g->size.x - 1
    && (contain(g->map[v.y][v.x + 1], "O ") || check_box(g, v, 1, 0));
}

void display_map(Game *g)
{
    for (int i = 0; i < g->size.y; i++) {
        move((g->max.x - g->size.y) / 2 + i, (g->max.y - g->size.x) / 2);
        for (int j = 0; j < g->size.x; j++)
            printw("%c", i != g->pos.y || j != g->pos.x ? g->map[i][j] : 'P');
        printw("%c");
    }
}

void reset_map(Game *g)
{
    g->pos = g->default_pos;
    for (int i = 0; i < g->size.y; i++)
        for (int j = 0; j < g->size.x; j++)
            g->map[i][j] = g->str[i * (g->size.x + 1) + j];
}

int display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap\tfile representing the warehouse map, containing '#' for");
    my_putstr(" walls,\n\t\t'P' for the player, 'X' for boxes and 'O' for");
    my_putstr(" storage locations.\n");
    return 0;
}
