/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** concat an array with linebreaks
*/

#include "include/my.h"

char *concat_params(int argc, char **argv)
{
    char *out;
    int n = 0;
    int len = 0;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]);

    out = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < argc; i++) {
        for (int j = 0; argv[i][j]; n++, j++)
            out[n] = argv[i][j];
        out[n] = '\n';
        n++;
    }
    out[len + 1] = 0;
    return out;
}
