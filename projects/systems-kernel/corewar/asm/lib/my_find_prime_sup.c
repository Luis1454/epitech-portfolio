/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday05-mathis.zucchero
** File description:
** my_find_prime_sup.c
*/

int prime(int nb)
{
    for (int prime = 2; prime < nb; prime++) {
        if (nb % prime == 0) {
            return 0;
        }
    }
    return 1;
}

int find_prime(int nbr)
{
    int may_prime = 0;
    for (int temp = nbr; temp < 25784; temp++) {
        may_prime = prime(temp);
        if (may_prime == 1) {
            return temp;
        }
    }
}

int my_find_prime_sup(int nb)
{
    int is_prime;
    int number = 0;

    is_prime = prime(nb);
    if (is_prime == 1)
        return nb;
    if (is_prime == 0)
        number = find_prime(nb);
        return nb;
}
