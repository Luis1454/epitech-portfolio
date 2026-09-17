/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** check functions
*/

#include "../includes/sokoban.h"
#include "../includes/my.h"

void check_map(Map *map)
{
    for (int i = 0; map->datas[i][0]; i++)
        for (int j = 0; map->datas[i][j]; j++)
            sub_check_map(map, i, j);
}

int check_free_space(Map *map, int i, int j)
{
    if (map->datas[i][j] == 'X')
        if ((map->datas[i - 1][j] == '#' || map->datas[i + 1][j] == '#'
        || map->datas[i - 1][j] == 'X' || map->datas[i + 1][j] == 'X')
        && (map->datas[i][j - 1] == '#' || map->datas[i][j + 1] == '#'
        || map->datas[i][j - 1] == 'X' || map->datas[i][j + 1] == 'X'))
            return 0;
        else
            return 1;
    return 0;
}
