/*
** EPITECH PROJECT, 2022
** my_print_error.c
** File description:
** display error
*/

#include <unistd.h>

static void my_char_error(char c)
{
    write(2, &c, 1);
}

int my_print_error(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_char_error(str[i]);
    return 0;
}

int my_putnbr_error(int nb)
{
    if (nb < 0) {
        my_char_error('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_putnbr_error(nb / 10);
    my_char_error(nb % 10 + '0');
    return 0;
}
