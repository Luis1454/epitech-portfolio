/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** get functions
*/

#include "../include/fasta.h"
#include "../include/my.h"

char **get_names(char *str, int len)
{
    char **out = malloc(sizeof(char *) * (len + 1));
    int n = 0;

    if (!out)
        return out;
    for (int i = 0; str[i]; i++)
        if (str[i] == '>')
            out[n++] = my_strdup_to(&str[i], "\n");
    out[n] = NULL;
    return out;
}
