/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** return the square root of a number
*/

int my_is_prime(int nb)
{
    for (int i = 2; i < nb; i++) {
        if (!(nb % i))
            return 0;
    }
    return 1 * nb > 1;
}
