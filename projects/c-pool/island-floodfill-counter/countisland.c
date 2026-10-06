/*
** EPITECH PROJECT, 2022
** countisland.c
** File description:
** countisland file
*/

#include "include/my.h"
#include "include/my_macro_abs.h"

void sum_sandbank(char **map, int i, int j, int *size)
{
    if (j + 1 < size[1] && map[i][j + 1] != '.') {
        map[i][j + 1] = map[i][j];
        sum_sandbank(map, i, j + 1, size);
    }
    if (i + 1 < size[0] && map[i + 1][j] != '.') {
        map[i + 1][j] = map[i][j];
        sum_sandbank(map, i + 1, j, size);
    }
}

sandbank_propagate(char **map, int i, int j, int *size)
{
    if (map[i][j] != '.') {
        if (j && map[i][j - 1] != '.') {
            map[i][j - 1] = map[i][j];
            sandbank_propagate(map, i, j - 1, size);
        }
        if (i && map[i - 1][j] != '.') {
            map[i - 1][j] = map[i][j];
            sandbank_propagate(map, i - 1, j, size);
        }
        sum_sandbank(map, i, j, size);
    }
    return map;
}

char *is_in_sentence(char c, char *str, int len)
{
    for (int i = 0; i < len; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int count_island(char **world)
{
    int nb = 0;
    int state = 1;
    int x = 0;
    int y = 0;
    int size[2] = {0};
    int n = 1;
    int cnt = 0;

    for (; world[size[0]] != NULL; size[0]++);
    for (; world[0][size[1]]; size[1]++);
    for (int i = 0; world[i] != NULL; i++) {
        for (int j = 0; world[i][j]; j++) {
            world[i][j] = (world[i][j] != '.') ? nb + '0' : '.';
            if (j && world[i][j - 1] != '.') {
                world[i][j] == world[i][j - 1];
                state = 1;
            } else if (state) {
                nb++;
                state = 0;
            }
            sandbank_propagate(world, i, j, size);
        }
    }
    for (int k = 0; k <= nb; k++, n = 1) {
        for (int i = 0; world[i] != NULL; i++)
            for (int j = 0; world[i][j]; j++) {
                if (world[i][j] == k + '0') {
                    if (n) {
                        world[i][j] = cnt + '0';
                        cnt++;
                        n = 0;
                    } else
                        world[i][j] = cnt - 1 + '0';
                }
            }
    }
    return cnt;
}
