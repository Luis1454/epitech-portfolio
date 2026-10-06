/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main function of the Infin_Add
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/main.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i][0]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

char *eval_expr(char *b_num, char *b_op, char *expr, int size)
{
    char *res;

    expr = fix_expr(expr, b_num, b_op);
    res = par_rec(expr, 0, 0, 0);
    res = fix_end_expr(res, b_num);
    return res;
}

char *fix_expr(char *expr, char *b_num, char *b_op)
{
    char **tab = malloc(sizeof(char*) * 2);
    int j = 0;

    for (int i = 0; i < 2; i++)
        tab[i] = malloc(sizeof(char) * 18);
    tab[0] = my_strcpy(tab[0], b_num);
    tab[0] = my_strcat(tab[0], b_op);
    tab[0][17] = '\0';
    tab[1] = "0123456789()+-*/%\0";
    for (int i = 0; expr[i]; i++) {
        for (j = 0; expr[i] != tab[0][j]; j++);
        expr[i] = tab[1][j];
    }
    return expr;
}

char *fix_end_expr(char *expr, char *b_num)
{
    char **tab = malloc(sizeof(char*) * 2);
    int j = 0;
    char *expr2 = malloc(sizeof(char) * (my_strlen(expr) + 1));

    for (int i = 0; i < 2; i++)
        tab[i] = malloc(sizeof(char) * 11);
    tab[0] = my_strcpy(tab[0], b_num);
    tab[0][10] = '\0';
    tab[1] = "0123456789\0";
    for (int i = 0; expr[i] != '\0'; i++) {
        for (j = 0; expr[i] != tab[1][j]; j++);
        expr2[i] = tab[0][j];
    }
    return expr2;
}
