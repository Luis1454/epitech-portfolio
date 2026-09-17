/*
** EPITECH PROJECT, 2021
** sub.c
** File description:
** sub functions
*/

#include "../includes/sokoban.h"
#include "../includes/my.h"

int sub_is_movable(Map *map, int i)
{
    for (int j = 0; map->datas[i][j]; j++)
        if (check_free_space(map, i, j))
            return 1;
    return 0;
}

int sub_still_rewards(Map *map, int i)
{
    for (int j = 0; map->datas[i][j]; j++)
        if (map->datas[i][j] == 'O'
        || (map->base[i][j] == 'O'
        && map->datas[i][j] == 'P'))
            return 1;
    return 0;
}

void sub_check_map(Map *map, int i, int j)
{
    char str[] = "O";

    for (int k = 0; k < my_strlen(str); k++)
        if (map->base[i][j] == str[k]
        && map->datas[i][j] != 'X')
            map->datas[i][j] = map->base[i][j];
}

int main_loop(Map map)
{
    while (still_rewards(&map)) {
        print_map(&map);
        if (!is_movable(&map)) {
            clear();
            endwin();
            return 1;
        }
        map.key = getch();
        get_key(&map);
        check_map(&map);
        place_player(map);
        clear();
    }
    return 0;
}

int sub_main(char *raw)
{
    Map map;

    map.datas = get_map(raw);
    if (map.datas == NULL
    || get_nb_char(map, 'X') != get_nb_char(map, 'O')
    || get_nb_char(map, 'P') != 1) {
        clear();
        endwin();
        return 84;
    }
    map.base = get_map(raw);
    if (main_loop(map))
        return 1;
    endwin();
    return 0;
}
