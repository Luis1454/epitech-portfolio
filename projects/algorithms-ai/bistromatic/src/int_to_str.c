/*
** EPITECH PROJECT, 2021
** int_to_str.c
** File description:
** int_to_str.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/main.h"

char *int_to_str_fix(char *str, int i)
{
    if (i == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
    }
    return str;
}

char *int_to_str_neg(char *str, int i)
{
    int j = 1;
    int c = 0;
    int k = 0;
    int temp = 0;

    if (i <= -1) {
        i *= -1;
        for (; i >= j; j *= 10, c++);
        str = malloc(sizeof(char) * (c + 1));
        str[0] = '-';
        for (; k < c; k++) {
            j /= 10;
            temp = (i / j);
            i -= (temp * j);
            str[k + 1] = (temp) + '0';
            str[k + 2] = '\0';
        }
        return str;
    }
    int_to_str_fix(str, i);
}

char *int_to_str(int i)
{
    int j = 1;
    int c = 0;
    int k = 0;
    int temp = 0;
    char *str;

    if (i >= 1) {
        for (; i >= j; j *= 10, c++);
        str = malloc(sizeof(char) * (c + 1));
        for (; k < c; k++) {
            j /= 10;
            temp = (i / j);
            i -= (temp * j);
            str[k] = (temp) + '0';
            str[k + 1] = '\0';
        }
        return str;
    }
    int_to_str_neg(str, i);
}
