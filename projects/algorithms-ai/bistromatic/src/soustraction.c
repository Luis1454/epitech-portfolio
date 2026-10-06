/*
** EPITECH PROJECT, 2021
** soustraction.c
** File description:
** soustraction
*/

#include "../include/my.h"
#include "../include/main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_neg(char *first, char *second)
{
    char *first_2 = my_strdup(first);
    char *second_2 = my_strdup(second);
    int a;
    int b;

    first_2 = supp_neg(first_2);
    second_2 = supp_neg(second_2);
    a = bigger_str_3(first_2, second_2);
    b = bigger_str_3(second_2, first_2);
    if (first[0] == '-' && a) {
        return 1;
    }
    if (second[0] == '-' && b) {
        return 1;
    }
    return 0;
}

char *soustraction(char *first, char *second)
{
    int neg = check_neg(first, second);
    int len_b = bigger_str(first, second);
    int len_s = smaller_str(first, second);
    char *res = malloc((len_b + 3) * sizeof(char));
    char *smaller_str;
    char *bigger_str;

    first = supp_neg(first);
    second = supp_neg(second);
    smaller_str = smaller_str_2(first, second);
    bigger_str = bigger_str_2(first, second);
    smaller_str = resize(smaller_str, len_b, len_s);
    for (int i = len_b - 1; i > -1; i--)
        res = soustraction_tools(bigger_str, smaller_str, res, i);
    while (res[0] == '0' && res[1] != '\0')
        res = rem_str(res);
    if (neg && res[0] != '0')
        res = add_str(res, '-');
    return res;
}

char *soustraction_tools(char *frst, char *secnd, char *res, int i)
{
    int temp = ((frst[i] - '0') - (secnd[i] - '0'));

    if (temp >= 0)
        res[i] = (temp + '0');
    if (temp < 0) {
        res[i] = ((10 + temp) + '0');
        frst[i - 1]--;
    }
    return res;
}

int bigger_str_3(char *first, char *second)
{
    int first_l = my_strlen(first);
    int second_l = my_strlen(second);
    int i;

    if (first_l > second_l)
        return 1;
    else if (first_l == second_l) {
        for (i = 0; first[i] == second[i]; i++);
        if (first[i] > second[i])
            return 1;
        else if (second[i] > first[i])
            return 0;
        else
            return 1;
    } else
        return 0;
}
