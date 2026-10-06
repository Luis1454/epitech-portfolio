/*
** EPITECH PROJECT, 2022
** len.c
** File description:
** use for len the map
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

int line_len(char *buffer)
{
    int i = 0;

    for (i; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    return i;
}

int nbr_line(char *buffer)
{
    int count = 0;
    int i = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    if (i > 0 && buffer[i] == '\0' && buffer[i - 1] != '\n')
        count++;
    return count;
}

int nbr_l(char **map)
{
    int i = 0;

    for (i = 0; map[i] != NULL ;i++);
    return i;
}

int nbr(char *str)
{
    int i = 0;
    int nbr = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 47 || str[i] > 58) {
            return 84;
        }
        nbr = nbr + (str[i] -48);
        nbr = nbr * 10;
    }
    nbr = nbr / 10;
    return nbr;
}
