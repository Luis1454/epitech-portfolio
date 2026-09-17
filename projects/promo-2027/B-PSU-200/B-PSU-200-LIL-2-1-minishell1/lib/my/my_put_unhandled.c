/*
** EPITECH PROJECT, 2022
** my_put_unhandled.c
** File description:
** display unhandled characters
*/

#include "../../include/my.h"

static long get_nb_len(long nb)
{
    long out = 0;

    for (; nb; nb /= 10, out++);
    return out;
}

static int format_number(long nb, int len)
{
    for (int i = 0; i < len - get_nb_len(my_getbase(nb, 8)); i++)
        my_putchar('0');
    if (nb)
        my_put_nbr(my_getbase(nb, 8), __INT_MAX__);
    return 0;
}

int my_put_unhandled(const unsigned char *str)
{
    if (!str) {
        my_putstr("(null)");
        return 0;
    }
    for (int i = 0; str[i]; i++) {
        if (32 <= str[i] && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            format_number(str[i], 3);
        }
    }
    return 0;
}
