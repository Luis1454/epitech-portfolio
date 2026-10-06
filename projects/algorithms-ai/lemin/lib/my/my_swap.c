/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** dsk
*/

#include "libmy.h"

int my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
    return (0);
}
