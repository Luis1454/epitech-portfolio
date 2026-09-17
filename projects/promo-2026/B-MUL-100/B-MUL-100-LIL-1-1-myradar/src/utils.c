/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** tools functions
*/

#include "../includes/include.h"
#include "../includes/my.h"

int test_null(FILE *fp)
{
    if (!fp) {
        my_putstr("./my_radar: name file not found.");
        return 1;
    }
    return 0;
}

sfColor get_color(int v)
{
    if (v)
        return sfGreen;
    return sfYellow;
}

int get_len_bf_dot(char *str)
{
    int i = 0;

    while (str[i] != '.' && i < my_strlen(str))
        i++;
    return i;
}

int are_equals(char *str, char *test)
{
    for (int i = 0; i < max(my_strlen(str), my_strlen(test)); i++)
        if (str[i] != test[i])
            return 0;
    return 1;
}
