/*
** EPITECH PROJECT, 2022
** task04
** File description:
** C pool day03
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
