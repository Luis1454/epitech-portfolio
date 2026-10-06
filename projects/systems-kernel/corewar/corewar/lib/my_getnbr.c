/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday04-mathis.zucchero
** File description:
** my_getnbr.c
*/

#include <stdio.h>

int my_strlen(char const *str, char delim);

int my_getnbr(char const *str, char delim)
{
    int i = 0;
    int is_neg = 0;
    int number = 0;

    if (str[0] && (str[0] == '-' || str[0] == '+')) {
        return 84;
    }
    for (int get = i - 1 + is_neg; get < my_strlen(str, delim); get++) {
        if (str[get] >= '0' && str[get] <= '9') {
            number = number * 10 + str[get] - 48;
        }
    }
    return (number);
}
