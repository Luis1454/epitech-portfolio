/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils functions
*/

#include "../include/ia_project.h"
#include "../include/my.h"

void free_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i])
            free(tab[i]);
    if (tab)
        free(tab);
}

int is_lidar(char **tab)
{
    for (int i = 0; tab[i]; i++)
        if (my_getnbr(tab[i]))
            return 1;
    return 0;
}

int go_back(char **tab)
{
    if (!tab)
        return 0;
    for (int i = 14; i < 15; i++)
        if (my_getnbr(tab[i]) < 300 - (i - 12) * 20)
            return 1;
    return 0;
}

float get_rot(char **tab)
{
    float out = 0;

    if (go_back(tab))
        return my_getnbr(tab[29]) > my_getnbr(tab[0]) ? 1.0 : -1.0;
    out += ((float)(my_getnbr(tab[0]) > 410)) /
    ((float)my_getnbr(tab[14])) * 100.0;
    out -= ((float)(my_getnbr(tab[29]) > 410)) /
    ((float)my_getnbr(tab[14])) * 100.0;
    return out > 1 ? 1 : out < -1 ? -1 : out;
}

float get_speed(char **tab)
{
    int rot = get_rot(tab) * 100.0;

    if (my_getnbr(tab[14]) > 2000 && !rot)
        return 1.0;
    if (my_getnbr(tab[14]) > 750 && !rot)
        return 0.5;
    if (my_getnbr(tab[14]) > 300 && !rot)
        return 0.3;
    if (my_getnbr(tab[14]) > 100 && !rot)
        return 0.15;
    return 0.2;
}
