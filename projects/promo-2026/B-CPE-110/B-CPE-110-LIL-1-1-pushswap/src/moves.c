/*
** EPITECH PROJECT, 2021
** moves.c
** File description:
** functions for moves
*/

#include "../includes/my.h"

int rev_rotate(int *l2, int len, int l, int i)
{
    int vect = 0;
    int tmp1 = l2[len - 1];
    int tmp2 = l2[0];
    int pos;

    if (i)
        my_putchar(' ');
    if (l)
        my_putstr("rrb");
    else
        my_putstr("rra");

    for (int i = 0; i < len - 1; i++) {
        pos = (i + 1) % len;
        tmp1 = l2[pos];
        l2[i] = tmp1;
    }
    l2[len - 1] = tmp2;
    return 1;
}

int rotate(int *l2, int len, int l)
{
    int vect = 0;
    int tmp1 = l2[0];
    int tmp2;

    if (l)
        my_putstr(" rb");
    else
        my_putstr(" ra");

    for (int i = 0; i < len; i++) {
        tmp2 = l2[(i + 1) % len];
        l2[(i + 1) % len] = tmp1;
        tmp1 = tmp2;
    }
    return 1;
}

int push_B(int *l1, int *l2, int len)
{
    int tmp1 = l2[0];
    int tmp2;

    if (!l1)
        return 84;

    my_putstr(" pb");
    l2[0] = l1[0];

    for (int i = 1; i < len; i++) {
        tmp2 = l2[i];
        l1[i - 1] = l1[i];
        l1[i] = tmp1;
        tmp1 = tmp2;
    }
    l1[len - 1] = 0;
    return 1;
}
