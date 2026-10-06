/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** dsk
*/

#include "libmy.h"

int my_nbrlen(int nb)
{
    int i = 0;

    if (nb < 0) {
        i++;
        nb = my_abs(nb);
    }
    for (; nb > 0; i++)
        nb = nb / 10;
    return (i);
}
