/*
** EPITECH PROJECT, 2023
** my_str_is_numb_modif
** File description:
** my_str_is_numb_modif
*/

#include "lemin.h"

int my_str_numb(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != c)
            return 1;
    }
    return 0;
}

int count_space(char *str)
{
    int i = 0;
    int t = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            t++;
    return (t);
}

int count_line(char **all_info)
{
    int i = 0;

    if (all_info == NULL)
        return (0);
    for (i = 0; all_info[i] != NULL; i++);
    return (i);
}

char *my_strndupp(char *str, int nb)
{
    char *new = malloc(sizeof(char) * (nb + 1));
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (; i < nb; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}
