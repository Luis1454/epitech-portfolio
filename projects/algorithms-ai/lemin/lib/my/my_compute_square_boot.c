/*
** EPITECH PROJECT, 2022
** my_compute_square_boot
** File description:
** dsk
*/

#include "libmy.h"

int my_compute_square_root(int nb)
{
    int i = 1;
    int b = 0;

    while (b < nb) {
        b = i * i;
        if (b == nb) {
            return (i);
        }
        i = i + 1;
    }
    return (0);
}
