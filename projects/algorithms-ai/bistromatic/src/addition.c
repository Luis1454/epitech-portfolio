/*
** EPITECH PROJECT, 2021
** addition.c
** File description:
** addition
*/

#include "../include/my.h"
#include "../include/main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *addition_2(char *first, char *second)
{
    int len_b = bigger_str(first, second) - 1;
    int len_s = smaller_str(first, second) - 1;
    char *res = malloc((len_b + 3) * sizeof(char));
    char *temp;
    char *smaller_str;
    char *bigger_str;

    if (first[0] == '-' && second[0] == '-' && first[0] == second[0]) {
        first = supp_neg(first);
        second = supp_neg(second);
    }
    temp = smaller_str_2(first, second);
    smaller_str = resize(temp, len_b, len_s);
    bigger_str = bigger_str_2(first, second);
    for (int i = len_b; i > -1; i--) {
        res = addition_tools(smaller_str, bigger_str, res, i);
    }
    res = add_str(res, '-');
    return res;
}

char *addition(char *first, char *second)
{
    int len_b = bigger_str(first, second);
    int len_s = smaller_str(first, second);
    char *res = malloc((len_b + 3) * sizeof(char));
    char *temp = smaller_str_2(first, second);
    char *smaller_str = resize(temp, len_b, len_s);
    char *bigger_str = bigger_str_2(first, second);

    for (int i = len_b - 1; i > -1; i--) {
        res = addition_tools(smaller_str, bigger_str, res, i);
    }
    return res;
}

char *addition_tools(char *frst, char *secnd, char *res, int i)
{
    int temp = ((frst[i] - '0') + (secnd[i]) - '0');

    if ((temp > 9 && frst[i - 1] < '9') || (temp > 9 && secnd[i - 1] < '9')) {
        if (frst[i - 1] < '9')
            frst[i - 1]++;
        else if (secnd[i - 1] < '9')
            secnd[i - 1]++;
    } else if (temp > 9 && frst[i - 1] == '9' && secnd[i - 1] == '9') {
        if (i == 0) {
            res[i] = ((((frst[i] - '0') + (secnd[i]) - '0') % 10) + '0');
            return res;
        }
        frst = fix_first(frst, i);
    }
    res[i] = ((((frst[i] - '0') + (secnd[i]) - '0') % 10) + '0');
    if (i == 0 && temp >= 9)
        res = add_str(res, '1');
    return res;
}

int a_check(char *frst, char *secnd, int i)
{
    if (frst[i] == '9' && secnd[i] == '9')
        return 1;
    else
        return 0;
}

char *fix_first(char *first, int i)
{
    first[i - 1] = '0';
    first[i - 2]++;
    return first;
}
