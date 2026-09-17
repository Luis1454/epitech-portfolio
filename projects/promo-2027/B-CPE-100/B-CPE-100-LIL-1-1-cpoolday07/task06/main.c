/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "../include/my.h"

int find_first_avaliable(int *tab, int len)
{
    for (int i = 0; i < len; i++)
        if (tab[i])
            return i;
    return len - 1;
}

int get_lower(char **args, int *tab, int len)
{
    int id = find_first_avaliable(tab, len);

    for (int i = 0; i < len; i++)
        if (tab[i] && my_strcmp(args[id], args[i]) > 0)
            id = i;
    my_putstr(args[id]);
    my_putchar('\n');
    return id;
}

int main(int argc, char *argv[])
{
    int tab[argc];
    int n;

    for (int i = 0; i < argc; i++)
        tab[i] = 1;
    for (int i = 0; i < argc; i++) {
        n = get_lower(argv, tab, argc);
        tab[n] = 0;
    }
    return 0;
}
