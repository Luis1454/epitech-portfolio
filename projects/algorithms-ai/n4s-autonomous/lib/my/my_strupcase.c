/*
** EPITECH PROJECT, 2022
** task 08
** File description:
** C pool day 06
*/

#include "../../include/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
