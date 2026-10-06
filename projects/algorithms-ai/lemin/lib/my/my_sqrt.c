/*
** EPITECH PROJECT, 2022
** my_sqrt
** File description:
** dsk
*/

#include "libmy.h"

double my_sqrt(double n)
{
    double x = n;
    double y = 1;
    double i = 0.000001;

    while (x - y > i) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}
