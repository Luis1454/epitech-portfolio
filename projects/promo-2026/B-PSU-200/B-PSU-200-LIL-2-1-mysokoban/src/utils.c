/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils functions
*/

#include "../includes/sokoban.h"
#include "../includes/my.h"

int is_movable(Map *map)
{
    for (int i = 0; map->datas[i][0]; i++)
        if (sub_is_movable(map, i))
            return 1;
    return 0;
}

int is_free(Map *map, int x, int y)
{
    char c = map->datas[map->player.X + x][map->player.Y + y];

    if (c == ' ' || c == 'O')
        return 1;
    else if (c == 'X'
    && (map->datas[map->player.X + x * 2][map->player.Y + y * 2] == 'O'
    || map->datas[map->player.X + x * 2][map->player.Y + y * 2] == ' ')) {
        map->datas[map->player.X + x * 2][map->player.Y + y * 2] = 'X';
        return 1;
    }
    return 0;
}

int still_rewards(Map *map)
{
    for (int i = 0; map->datas[i][0]; i++)
        if (sub_still_rewards(map, i))
            return 1;
    return 0;
}

void get_key(Map *map)
{
    if ((map->key == KEY_UP) && is_free(map, -1, 0))
        map->player.X--;
    if ((map->key == KEY_DOWN) && is_free(map, 1, 0))
        map->player.X++;
    if ((map->key == KEY_LEFT) && is_free(map, 0, -1))
        map->player.Y--;
    if ((map->key == KEY_RIGHT) && is_free(map, 0, 1))
        map->player.Y++;
}

int get_nb_char(Map map, char c)
{
    int nb = 0;

    for (int i = 0; i < map.datas[i][0]; i++)
        for (int j = 0; map.datas[i][j]; j++)
            nb += map.datas[i][j] == c;
    return nb;
}
