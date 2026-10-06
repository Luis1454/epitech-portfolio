/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** dsk
*/

#include "libmy.h"

char *my_strcat(char *dest, char const *src)
{
    size_t dest_size = my_strlen(dest);
    size_t src_size = my_strlen(src);
    char *new_dest = (char *)malloc(dest_size + src_size + 1);
    for (size_t i = 0; i < dest_size; i++)
        new_dest[i] = dest[i];
    for (size_t i = 0; i <= src_size; i++)
        new_dest[dest_size + i] = src[i];
    free(dest);
    dest = my_strdup(new_dest);
    return dest;
}
