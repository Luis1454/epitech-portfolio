/*
** EPITECH PROJECT, 2022
** display_error.c
** File description:
** functions for error messages
*/

#include "../../include/my.h"

int my_print_error(const char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return len;
}

char *my_itoa(int nb)
{
    int len = 0;
    int tmp = nb;
    char *str;

    if (!nb) {
        str = my_strdup("0");
        return str;
    }
    for (; tmp; len++, tmp /= 10);
    str = malloc(sizeof(char) * (len + 1));
    str[len] = 0;
    for (int i = len - 1; i >= 0; i--, nb /= 10)
        str[i] = nb % 10 + '0';
    return str;
}

int my_print_nbr_error(int nb)
{
    char *str = my_itoa(nb);
    int len = my_print_error(str);

    free(str);
    return len;
}
