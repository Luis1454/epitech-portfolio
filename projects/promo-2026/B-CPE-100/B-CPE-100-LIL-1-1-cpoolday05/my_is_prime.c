/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int s = 1;
    int i;

    for (i = 2; i < nb; i++) {
        if (nb % i == 0){
            s = 0;
            break;
        }
    }

    if (nb > 1)
        return s;
    else
        return 0;

}