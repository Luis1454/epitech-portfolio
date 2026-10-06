/*
** EPITECH PROJECT, 2023
** assert.c
** File description:
** assertion functions
*/

#include "../include/my.h"
#include "../include/minishell.h"

int is_dir(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
        return 0;
    return S_ISDIR(sb.st_mode);
}

int count_char(const char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count += str[i] == c && (!i || str[i - 1] != '\\');
    return count;
}
