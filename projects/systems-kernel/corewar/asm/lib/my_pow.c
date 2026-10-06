/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_pow.c
*/

int my_pow(int nb, int p)
{
    int res = 1;

    if (p == 0)
        return 1;
    for (int i = 0; i < p; i++)
        res *= nb;
    return res;
}
