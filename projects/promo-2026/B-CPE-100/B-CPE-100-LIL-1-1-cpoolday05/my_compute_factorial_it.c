/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** task01
*/

int my_compute_factorial_it(int nb)
{
    int s = 1;
    int cnt = nb;

    while (cnt > 0) {
        s *= cnt;
        cnt--;
    }

    if (nb > 12 || nb < 0)
    	return 0;
    else
    	return s;
}