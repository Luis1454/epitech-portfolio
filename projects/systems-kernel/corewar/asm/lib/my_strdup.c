/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
