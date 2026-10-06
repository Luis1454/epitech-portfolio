/*
** EPITECH PROJECT, 2022
** my_itoa
** File description:
** dsk
*/

#include "libmy.h"

char *my_itoa(int number)
{
    int i = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 12);
    if (number < 0) {
        str[i] = '-';
        i++;
        number = number * -1;
    }
    while (number > 0) {
        str[i] = number % 10 + 48;
        number = number / 10;
        i++;
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        k = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = k;
    }
    return (str);
}
