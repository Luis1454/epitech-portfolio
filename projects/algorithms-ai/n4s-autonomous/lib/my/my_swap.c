/*
** EPITECH PROJECT, 2022
** task01
** File description:
** C pool day 04
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
