/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for my_radar
*/

#include "../includes/include.h"
#include "../includes/my.h"
#include <stdlib.h>

int show_usage(void)
{
    char *line = 0;
    size_t l = 0;
    FILE *fp = fopen("readme.usage", "r");

    if (!fp)
        return 0;
    while ((getline(&line, &l, fp)) != -1)
        my_putstr(line);
    free(line);
    return 1;
}

int show_legend(void)
{
    char *line = 0;
    size_t l = 0;
    FILE *fp = fopen("readme.legend", "r");

    if (!fp)
        return 0;
    while ((getline(&line, &l, fp)) != -1)
        my_putstr(line);
    free(line);
    return 1;
}

int main(int argc, char *argv[])
{
    Stat *stat = malloc(sizeof(Stat));
    stat->nbPlanes = 10000;
    stat->nbTowers = 10000;
    Plane planes[stat->nbPlanes];
    Tower towers[stat->nbTowers];

    if (argc != 2)
        return 84;
    if (are_equals(argv[1], "-h")
    || are_equals(argv[1], "--help")
    || are_equals(argv[1], "--usage"))
        return show_usage();
    else if (are_equals(argv[1], "-l")
    || are_equals(argv[1], "--legend"))
        return show_legend();
    if (!parser(argv[1], planes, towers))
        return 84;
    return my_radar(stat, planes, towers);
}
