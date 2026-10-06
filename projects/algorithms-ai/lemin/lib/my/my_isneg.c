/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** dsk
*/

#include "libmy.h"

void my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
