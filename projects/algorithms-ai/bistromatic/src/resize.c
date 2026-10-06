/*
** EPITECH PROJECT, 2021
** resize.c
** File description:
** resize
*/

#include "../include/my.h"
#include "../include/main.h"
#include <stdlib.h>

char *resize(char *str, int len_b, int len_s)
{
    int len = (len_b - len_s);
    char *dest = malloc(sizeof(char) * (len_b + 1));

    for (int i = 0; i < len; i++)
        dest[i] = '0';
    my_strcat(dest, str);
    return dest;
}

int bigger_str(char *first, char *second)
{
    int first_l = my_strlen(first);
    int second_l = my_strlen(second);
    if (second[0] == '-')
        second_l--;
    if (first[0] == '-')
        first_l--;
    if (first_l >= second_l)
        return first_l;
    return second_l;
}

int smaller_str(char *first, char *second)
{
    int first_l = my_strlen(first);
    int second_l = my_strlen(second);

    if (second[0] == '-')
        second_l--;
    if (first[0] == '-')
        first_l--;
    if (first_l <= second_l)
        return first_l;
    return second_l;
}

char *smaller_str_2(char *first, char *second)
{
    int first_l = my_strlen(first);
    int second_l = my_strlen(second);
    int i;

    if (first_l < second_l)
        return first;
    else if (first_l == second_l) {
        for (i = 0; first[i] == second[i]; i++);
        if (first[i] < second[i])
            return first;
        else if (second[i] < first[i])
            return second;
        else
            return second;
    } else
        return second;
}

char *bigger_str_2(char *first, char *second)
{
    int first_l = my_strlen(first);
    int second_l = my_strlen(second);
    int i;

    if (first_l > second_l)
        return first;
    else if (first_l == second_l) {
        for (i = 0; first[i] == second[i]; i++);
        if (first[i] > second[i])
            return first;
        else if (second[i] > first[i])
            return second;
        else
            return first;
    } else
        return second;
}
