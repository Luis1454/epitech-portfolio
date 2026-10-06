/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** dsk
*/

#include "libmy.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = my_abs(nb);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(nb + '0');
}
