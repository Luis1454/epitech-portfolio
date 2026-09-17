/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** task02
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcat(char *dest , char const *src);

int my_strlen(char const *str);

char *concat_params(int argc , char **argv)
{
    int len;
    int cnt;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]) + 1;

    char *out = malloc(len);

    for (int i = 0; i < argc; i++) {
        my_strcat(out, argv[i]);
        my_strcat(out, "\n");
    }
    out[len-1] = '\0';
    return out;
}
