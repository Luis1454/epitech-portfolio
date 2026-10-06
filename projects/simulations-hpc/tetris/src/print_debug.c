/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** print debug
*/

#include "../includes/tetris.h"
#include "../includes/my.h"

void print(char *A, int n, char *B)
{
    my_putstr(A);
    my_put_nbr(n);
    my_putstr(B);
}

void nprint(int A, char *str, int B)
{
    my_put_nbr(A);
    my_putstr(str);
    my_put_nbr(B);
}

void strprint(char *A, char *str, char *B)
{
    my_putstr(A);
    my_putstr(str);
    my_putstr(B);
}

void print_block(int *shape_i, int len, int j)
{
    for (int k = j; k < len; k++) {
        if (shape_i[k]) {
            my_putchar(shape_i[j] ? '*' : ' ');
            break;
        }
    }
}

void print_map(Game *g, int n)
{
    for (int i = 0; i < g->pieces[n].size.y; i++) {
        for (int j = 0; j < g->pieces[n].size.x; j++)
            print_block(g->pieces[n].shape[i], g->pieces[n].size.x, j);
        my_putchar('\n');
    }
}
