/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** check functions
*/

#include "../includes/main.h"

int is_sorted(int *lst, int len)
{
    for (int i = 1; i < len - 1; i++)
        if (lst[i] > lst[i + 1])
            return 0;
    return 1;
}

int is_empty(int *l2, int len)
{
    int i = 0;

    for (int i = 0; i < len; ++i) {
        if (l2[i])
            return 0;
        i++;
    }
    return 1;
}
