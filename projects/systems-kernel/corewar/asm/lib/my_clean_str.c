/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_clean_str.c
*/

#include <stddef.h>
#include <stdlib.h>

char *my_c_clean_str(char *src, char c)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;
    int j = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i] != '\0'; i++) {
        if (src[i] == ' ' && i == 0)
            continue;
        if (src[i] == ' ' && (src[i + 1] != '\0' && src[i + 1] == ' '))
            continue;
        if (src[i] == c)
            continue;
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return dest;
}

char *my_clean_str(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;
    int j = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i] != '\0'; i++) {
        if (src[i] == ' ' && i == 0)
            continue;
        if (src[i] == ' ' && (src[i + 1] != '\0' && src[i + 1] == ' '))
            continue;
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return dest;
}
