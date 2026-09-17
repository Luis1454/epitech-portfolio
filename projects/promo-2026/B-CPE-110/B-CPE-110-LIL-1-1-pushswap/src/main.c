/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file
*/

#include "../includes/my.h"
#include "../includes/main.h"
#include <stdio.h>

int sub_pushswap(int *lst1, int len, int i)
{
    int here;
    long int val = 1000000000000000000;

    for (int j = 0; j < len; j++) {
        if (lst1[0] < val && lst1[0]) {
            val = lst1[0];
            here = j;
        }
        rev_rotate(lst1, len, 0, i + j);
    }
    return here;
}

int pushswap(int *lst1, int *lst2, int len)
{
    int here;
    for (int i = 0; i < len; i++) {
        here = sub_pushswap(lst1, len, i);
        for (int j = 0; j < here; j++)
            rev_rotate(lst1, len, 0, 1);
        push_B(lst1, lst2, len);
        rev_rotate(lst2, len, 1, 1);
    }
    my_putchar('\n');
    return 0;
}

int main(int argc, char const *argv[])
{
    int len = argc - 1;
    int lst1[len];
    int lst2[len];

    for (int i = 0; i < len; i++) {
        lst1[i] = 0;
        lst2[i] = 0;
    }
    if (argc < 2)
        return 84;
    for (int i = 1; i < argc; i++) {
        lst1[i - 1] = my_getnbr(argv[i]);
    }

    pushswap(lst1, lst2, len);
    return 0;
}
