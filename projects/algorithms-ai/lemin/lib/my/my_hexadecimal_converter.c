/*
** EPITECH PROJECT, 2022
** my_hexadecimal_converter
** File description:
** dsk
*/

#include "libmy.h"

char *my_hexadecimal_converter(int nb, int maj)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100);
    char *hexa = "0123456789abcdef";
    char *hexa_maj = "0123456789ABCDEF";

    if (nb < 0)
        nb = nb * -1;
    while (nb > 0) {
        if (maj == 0)
            str[i] = hexa[nb % 16];
        else
            str[i] = hexa_maj[nb % 16];
        nb = nb / 16;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
