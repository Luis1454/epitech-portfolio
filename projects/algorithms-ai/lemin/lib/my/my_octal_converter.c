/*
** EPITECH PROJECT, 2022
** my_octal_converter
** File description:
** dsk
*/

#include "libmy.h"

int my_octal_converter(int nb)
{
    int octal = 0;
    int i = 1;

    while (nb != 0) {
        octal += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    return (octal);
}
