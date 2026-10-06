/*
** EPITECH PROJECT, 2021
** tools.c
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/main.h"
#include <stdlib.h>

char *core(char *frst, char *second)
{
    char *res;
    if ((frst[0] == '-' || second[0] == '-') && frst[0] != second[0]) {
        res = soustraction(frst, second);
        return res;
    } else if ((frst[0] == '-' || second[0] == '-') && frst[0] == second[0]) {
        res = addition_2(frst, second);
        return res;
    } else {
        res = addition(frst, second);
        return res;
    }
}

char *add_str(char *str, char c)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (len + 2));
    res[0] = c;
    my_strcat(res, str);
    return res;
}

char *supp_neg(char *str)
{
    int i = 0;

    if (str[0] == '-') {
        for (; str[i]; i++)
            str[i] = str[i + 1];
        str[i] = '\0';
    }
    return str;
}

char *rem_str(char *str)
{
    int i = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; str[i]; i++)
        res[i] = str[i + 1];
    res[i] = '\0';
    return res; 
}