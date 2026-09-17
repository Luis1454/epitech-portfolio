/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** task07
*/

int my_isa_prime(int nb)
{
    int i;

    i = 1;
    if (nb < 1)
        return 0;
    while (i <= nb) {
        if ((nb % i) == 0 && nb != i && i > 1) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;

}

int my_find_prime_sup(int nb)
{
    int i;

    i = nb;
    while (my_isa_prime(i) != 1) {
        i++;
    }
    return i;
}
