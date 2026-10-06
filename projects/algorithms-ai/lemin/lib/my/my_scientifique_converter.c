/*
** EPITECH PROJECT, 2022
** my_scientifique_converter
** File description:
** dsk
*/

#include "libmy.h"

int my_scientifique_converterp(double nb, int maj, int countinv, int count)
{
    my_putfloat(nb, 6);
    if (maj == 1)
        my_putchar('E');
    else
        my_putchar('e');
    if (countinv > 0)
        my_putchar('-');
    else
        my_putchar('+');
    if (count < 10)
        my_putnbr(0);
    my_putnbr(count - countinv);
    return (0);
}

int my_scientifique_converter(double nb, int maj)
{
    int countinv = 0;
    int count = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb < 1) {
        nb = nb * 10;
        countinv++;
    }
    while (nb >= 10) {
        nb = nb / 10;
        count++;
    }
    my_scientifique_converterp(nb, maj, countinv, count);
    return (0);
}
