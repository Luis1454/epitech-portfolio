/*
** EPITECH PROJECT, 2022
** task 06
** File description:
** C pool day 05
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return 0;
    while (i < nb) {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
