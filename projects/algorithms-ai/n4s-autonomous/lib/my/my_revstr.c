/*
** EPITECH PROJECT, 2022
** task 03
** File description:
** C pool day 06
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int temp;
    while (i != my_strlen(str) / 2) {
        temp = str[i];
        str[i] = str[my_strlen(str)- i - 1];
        str[my_strlen(str)- i - 1] = temp;
        i++;
    }
    return str;
}
