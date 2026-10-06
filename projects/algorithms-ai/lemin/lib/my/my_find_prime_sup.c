/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** dsk
*/

#include "libmy.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        return (2);
    for (int i = nb; i < nb * nb; i++) {
        if (my_is_prime(i))
            return (i);
    }
    return (0);
}
