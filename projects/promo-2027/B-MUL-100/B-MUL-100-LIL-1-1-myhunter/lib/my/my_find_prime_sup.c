/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** return the square root of a number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (; !my_is_prime(nb); nb++);
    return nb;
}
