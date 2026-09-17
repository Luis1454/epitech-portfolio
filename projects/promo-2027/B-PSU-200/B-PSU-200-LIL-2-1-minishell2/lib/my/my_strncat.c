/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; i < src[i] && i < nb; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}

char *my_weak_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;
    char *tmp = malloc(sizeof(char) * (len + my_strlen(src) + 1));

    for (int j = 0; dest[j]; tmp[j] = dest[j], j++);
    for (; src[i]; tmp[len + i] = src[i], i++);
    tmp[len + i] = 0;
    dest = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    for (int j = 0; tmp[j]; dest[j] = tmp[j], j++);
    dest[my_strlen(tmp)] = 0;
    free(tmp);
    return dest;
}
