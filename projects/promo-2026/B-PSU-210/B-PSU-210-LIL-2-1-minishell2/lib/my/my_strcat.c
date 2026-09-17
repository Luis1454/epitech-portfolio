/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task01
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}

char *my_weak_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;
    char *tmp = malloc(sizeof(char) * (len + my_strlen(src) + 1));

    for (int j = 0; dest[j]; j++)
        tmp[j] = dest[j];
    for (; src[i]; i++)
        tmp[len + i] = src[i];
    tmp[len + i] = 0;
    dest = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    for (int j = 0; tmp[j]; j++)
        dest[j] = tmp[j];
    dest[my_strlen(tmp)] = 0;
    free(tmp);
    return dest;
}
