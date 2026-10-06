/*
** EPITECH PROJECT, 2021
** parenthesis.c
** File description:
** File that handles parenthesis
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/main.h"

int par_open_check(char *str, int k, int p, int *d)
{
    if (str[k] == '(') {
        if (p == 0)
            d[0] = k + 1;
        p++;
    }
    return (p);
}

int par_close_check(char *str, int k, int p, int *e)
{
    if (str[k] == ')') {
        if (p == 1)
            e[0] = k - 1;
        p--;
    }
    return (p);
}

int mini_filler(char **res, char *copy, int p)
{
    for (int k = 0; copy[k] != '\0'; k++) {
        res[0][p] = copy[k];
        p++;
    }
    return (p);
}

char *str_adder(char *str, char *copy, int d, int e)
{
    int p = 0;
    char *res = malloc(sizeof(char) * (my_strlen(copy) + my_strlen(str) + 1));

    for (int k = 0; str[k] != '\0'; k++) {
        if (k < (d - 1) || k > (e + 1)) {
            res[p] = str[k];
            p++;
        }
        else if (k == (d - 1))
            p = mini_filler(&res, copy, p);
    }
    return (res);
}

char *par_rec(char *str, int p, int d, int e)
{
    int save = 0;
    char *copy = malloc(sizeof(char) * my_strlen(str));

    for (int k = 0; str[k] != '\0'; k++) {
        if (p != 0)
            copy[k - d] = str[k];
        p = par_open_check(str, k, p, &d);
        p = par_close_check(str, k, p, &e);
        if (p == 0 && e != 0) {
            copy[k - d] = '\0';
            save = my_strlen(copy) + 1;
            copy = par_rec(copy, 0, 0, 0);
            k = k - save + my_strlen(copy);
            str = str_adder(str, copy, d, e);
            d = 0;
            e = 0;
        }
    }
    str = calculus(str);
    return (str);
}
