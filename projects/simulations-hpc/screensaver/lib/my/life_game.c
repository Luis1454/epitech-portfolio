/*
** EPITECH PROJECT, 2021
** life_game.c
** File description:
** life game functions
*/

#include <stdlib.h>
#include "../../include/include.h"
#include "../../include/my.h"

int make_life(int **map, int x, int y, int Xsize)
{
    int nb = 0;
    int a = rand() % 2;
    int b = rand() % 2;

    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            nb += map[i][j];
    if (!map[x][y]) {
        if (nb == 3) {
            map[x][y] = a;
            return a;
        }
    } else if (nb - 1 == 2 || nb - 1 == 3) {
            map[x][y] = b;
            return b;
    } else {
        map[x][y] = 1;
        return 1;
    }
}

int make_life_2(int **map, int x, int y, int Xsize)
{
    int rnd = rand() % (Xsize - 100) * Xsize + 100;
    int nb = 0;

    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            nb += map[i][j];
    if (map[x][y])
        if (2 > nb - 1 || nb - 1 > 3) {
            map[x + rand() % 2 - 1][y + rnd] = 0;
            return 0;
        }
    else if (rand() % 10 < nb && nb < rand() % 10) {
        map[x + 1][y + rnd] = 1;
        return 1;
    }
    map[x][y + 100] = 1;
    return 0;
}

sfColor *life_game(sfColor *pixels, int **field, int Xsize, int Ysize)
{
    int v = 0;
    int off = 1;

    for (int i = off; i < Xsize - off; i++)
        for (int j = off; j < Ysize - off; j++) {
            v = make_life(field, i, j, Xsize);
            pixels[i * Xsize + (Xsize - Ysize) / 2 + j] =
            get_rgb(v * 255, v * 255, v * 255);
        }
}
