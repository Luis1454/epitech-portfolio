/*
** EPITECH PROJECT, 2022
** task 07
** File description:
** C pool day 05
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (nb <= 1)
        return 2;
    while (i < nb * nb) {
        if (my_is_prime(i) == 0)
            my_is_prime(i + 1);
        i++;
    }
    return nb;
}
