/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** dsk
*/

#include "libmy.h"

char *my_strncat(char *dest, char *src, int n)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; j < n; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}
