/*
** EPITECH PROJECT, 2021
** calculus.c
** File description:
** File that calcul string
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/main.h"

char *calculus(char *str)
{
    char **tab = tab_do_op(str);
    char *res;
    int k = 0;
    if (tab[1][0] == '\0') {
        res = tab[0];
        return res;
    }
    for (int k = 1; tab[k - 1]; k += 2) {
        if (tab[k][0] == '%' || tab[k][0] == '*' || tab[k][0] == '/') {
            res = calculus_k(tab , k, res);
            k -= 2;
        }
    }
    for (k = 1;tab[k][0]; ) {
        if (tab[k][0] == '+' || tab[k][0] == '-') {
            res = calculus_k(tab, k, res);
        }
    }
    return res;
}

char **decale_tab(char *res, char **tab, int k)
{
    int i = k;

    tab[i - 1] = res;
    for (; tab[i] && tab[i + 2]; i += 2) {
        tab[i] = tab[i + 2];
        tab[i + 1] = tab[i + 3];
    }
    return tab;
}

char **tab_do_op(char *str)
{
    char **tab = malloc(sizeof(char *) * len_tab(str));
    int i = 0;
    int j = 0;
    int c = 0;

    for (int c = 0; c < len_tab(str); c++)
        tab[c] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (int k = 0; str[k]; k++, i++ , j = 0) {
        str = decale_plus(str, k);
        for (c = k; (str[k] >= '0' && str[k] <= '9') || str[c] == '-'; j++) {
            tab[i][j] = str[k];
            k++;
            c = my_strlen(str);
        }
        tab[i][j] = '\0';
        i++;
        tab[i][0] = str[k];
        tab[i][1] = '\0';
    }
    return tab;
}

int len_tab(char *str)
{
    int c = 0;

    for (int i = 0; str[i]; i++) {
        for (int j = 0; str[i] >= '0' && str[i] <= '9'; j++, i++);
        c += 2;
    }
    return c;
}

char *calculus_k(char **tab, int k, char *res)
{
    res = do_op(tab[k - 1], tab[k], tab[k + 1], 0);
    tab = decale_tab(res, tab, k);
    return res;
}
