/*
** EPITECH PROJECT, 2022
** my_abs
** File description:
** dsk
*/

#include "libmy.h"

int my_abs(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}
