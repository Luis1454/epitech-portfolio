/*
** EPITECH PROJECT, 2022
** my_binary_converter
** File description:
** dsk
*/

#include "libmy.h"

int my_binary_converter(int nb)
{
    int i = 1;
    int bin = 0;

    while (nb != 0) {
        bin += (nb % 2)*i;
        nb /= 2;
        i *= 10;
    }
    my_putnbr(bin);
    return (0);
}
