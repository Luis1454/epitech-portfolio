/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** bsq utils file
*/

#include "../include/my.h"

int get_size_x(const char *str)
{
    int n = 0;
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            n = j > n ? j : n;
            j = 0;
        } else
            j++;
    }
    return n;
}

int get_size_y(const char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; nb += str[i] == '\n', i++);
    return nb;
}

int free_map(char **map, int size)
{
    if (map != NULL) {
        for (int i = 0; i < size; i++)
            map[i] != NULL ? free(map[i]) : 0;
        free(map);
    }
    return 0;
}

int get_nb(const char c, const char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        nb += str[i] == c;
    return nb;
}
