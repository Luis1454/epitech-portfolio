/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../../include/my.h"

char* my_strdup(char* str)
{
    int len = my_strlen(str);
    char* dest = malloc(len + 1);

    if(dest == NULL)
        return (NULL);
    dest = my_strcpy(dest, str);
    dest[len] = '\0';
    return (dest);
}