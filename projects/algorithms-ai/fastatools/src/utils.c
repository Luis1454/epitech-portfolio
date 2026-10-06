/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils functions
*/

#include "../include/my.h"
#include "../include/fasta.h"

int start_by(char *str, char *pattern)
{
    for (int i = 0; pattern[i]; i++)
        if (str[i] != pattern[i])
            return 0;
    return 1;
}

static int sub_get_str_pos(char *str, char **pattern, int i)
{
    for (int j = 0; pattern[j]; j++)
        if (start_by(&str[i], pattern[j]))
            return i;
    return -1;
}

int get_str_pos(char *str, char **pattern)
{
    int pos = 0;

    for (int i = 0; str[i]; i++)
        if ((pos = sub_get_str_pos(str, pattern, i)) != -1)
            return pos;
    return -1;
}
