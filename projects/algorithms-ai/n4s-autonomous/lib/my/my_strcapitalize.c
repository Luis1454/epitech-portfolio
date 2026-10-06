/*
** EPITECH PROJECT, 2022
** task 10
** File description:
** C pool day 06
*/

#include "../../include/my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122 && (str[i - 1] < 48 ||
        str[i - 1] > 57) && (str[i - 1] < 65 || str[i - 1] > 90) && (str[i - 1]
        < 97 || str[i - 1] > 122)) {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
