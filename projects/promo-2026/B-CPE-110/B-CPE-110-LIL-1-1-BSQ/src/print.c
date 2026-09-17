/*
** EPITECH PROJECT, 2021
** print.c
** File description:
** printing functions
*/

#include "../include/my.h"

void print_array(char **arr, int a, int b)
{
    for (int i = 0; i < a; i++) {
        for (int j = 2; j < b + 1; j++)
            my_putchar(arr[i][j]);
        my_putchar('\n');
    }
}

void print_num_array(int **arr, int a, int b)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            my_put_nbr(arr[i][j]);
        my_putchar('\n');
    }
}
