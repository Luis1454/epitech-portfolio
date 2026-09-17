/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** task07
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int s;
    int i = 0;

    while (1)
    {
        if (my_is_prime(nb+i))
            break;

        i++;
    }

    s = nb+i;

    return s;
}