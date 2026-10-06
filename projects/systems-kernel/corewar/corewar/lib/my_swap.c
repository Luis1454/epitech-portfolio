/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday04-mathis.zucchero
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int c = *a;
    int d = *b;
    *a = d;
    *b = c;
}
