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
