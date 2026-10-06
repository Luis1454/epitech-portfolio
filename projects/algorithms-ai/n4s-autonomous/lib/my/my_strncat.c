/*
** EPITECH PROJECT, 2022
** task 03
** File description:
** C pool day 07
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    while (src[i] != '\0' && i < nb) {
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
