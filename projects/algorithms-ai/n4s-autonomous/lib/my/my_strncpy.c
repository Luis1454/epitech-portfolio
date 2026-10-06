/*
** EPITECH PROJECT, 2022
** task 02
** File description:
** C pool day 06
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n ) {
        dest[i] = src[i];
        i++;
    }
    if (n > i){
        dest[i] = '\0';
    }
    return (dest);
}
