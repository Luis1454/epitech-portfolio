/*
** EPITECH PROJECT, 2021
** iterative_factorial.c
** File description:
** return factorial
*/

int iterative_factorial(int nb)
{
    int out = 1;

    if (nb >= 0) {
        for (int i = 1; i <= nb; i++)
            out *= i;
        if (nb < 13)
            return out;
    }
    return 0;
}
