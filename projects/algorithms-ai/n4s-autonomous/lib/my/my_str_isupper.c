/*
** EPITECH PROJECT, 2022
** task 15
** File description:
** C pool day 06
*/

#include "../../include/my.h"
int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 90) {
            return 0;
        }
        i++;
    }
    return 1;
}
