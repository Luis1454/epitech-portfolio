/*
** EPITECH PROJECT, 2021
** is_prime_number.c
** File description:
** return a boolean for a prime
*/

int is_prime_number(int nb)
{
    int i = 2;

    if (nb < i)
        return 0;
    while (i < nb) {
        if (!(nb % i))
            return 0;
        i++;
    }
    return 1;
}
