/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday05-mathis.zucchero
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{

    for (int prime = 2 ; prime < nb; prime++) {
        if (nb % prime == 0) {
            return 0;
        }
    }
    return 1;
}
