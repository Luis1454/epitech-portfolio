/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** my own ls function
*/

#include "../include/my.h"
#include <dirent.h>

int my_ls(char *str)
{
    DIR *dir = opendir(str);
    struct dirent *read;

    if (dir == 0)
        return 0;
    while ((read = readdir(dir))) {
        if (read->d_name[0] != '.')
            my_printf("%s  ", read->d_name);
    }
    my_printf("\n");
    return 1;
}

int main(int argc, char *argv[])
{
    int *flags;
    char *path = ".";
    int v = 1;

    if (argc == 1)
        my_ls(path);
    else {
        path = argv[1];
        for (int i = 1; i < argc && v; i++)
            v = my_ls(path);
        if (!v)
            return 84;
    }
    return 0;
}
