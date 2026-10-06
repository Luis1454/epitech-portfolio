/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** dsk
*/

#include "libmy.h"

int my_putnbr_base(long nb, char const *base)
{
    int len = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= len) {
        my_putnbr_base(nb / len, base);
        my_putnbr_base(nb % len, base);
    } else
        my_putchar(base[nb]);
    return (0);
}
