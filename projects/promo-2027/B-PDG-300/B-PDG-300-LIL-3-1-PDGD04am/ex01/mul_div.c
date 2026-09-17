/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main file
*/

#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b ? a / b : 42;
}

void mul_div_short(int *a, int *b)
{
    int tmp_a = *a;
    int tmp_b = *b;

    *a = tmp_a * tmp_b;
    *b = tmp_b ? tmp_a / tmp_b : 42;
}
