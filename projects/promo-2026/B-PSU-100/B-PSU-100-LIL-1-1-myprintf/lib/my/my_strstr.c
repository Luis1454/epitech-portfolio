/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** task05
*/

#include <stddef.h>

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        while (str[i] == to_find[j] && to_find[j] != '\0') {
            i++;
            j++;
        }
        if (to_find[j] == '\0')
            return str + i - j;
        k++;
        i = k;
        j = 0;
    }
    return NULL;
}
