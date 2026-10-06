/*
** EPITECH PROJECT, 2022
** task 12
** File description:
** C pool day 06
*/

#include "../../include/my.h"

int my_str_isalpha(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

int my_str_isalphanum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
    }
    return 1;
}
