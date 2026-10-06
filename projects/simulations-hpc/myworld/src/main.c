/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file
*/

#include "../includes/my.h"
#include "../includes/my_world.h"

int show_usage(void)
{
    char *line = 0;
    size_t l = 0;
    FILE *fp = fopen("readme.usage", "r");

    if (!fp)
        return 0;
    while ((getline(&line, &l, fp)) != -1)
        my_putstr(line);
    free(line);
    return 1;
}

int show_legend(void)
{
    char *line = 0;
    size_t l = 0;
    FILE *fp = fopen("readme.legend", "r");

    if (!fp)
        return 0;
    while ((getline(&line, &l, fp)) != -1)
        my_putstr(line);
    free(line);
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc > 2)
        return 84;
    if (argc == 2) {
        if (are_equals(argv[1], "-h")
        || are_equals(argv[1], "--help")
        || are_equals(argv[1], "--usage"))
            return show_usage();
        else if (are_equals(argv[1], "-l")
        || are_equals(argv[1], "--legend"))
            return 0;
        else
            return 84;
    }
    return my_world();
}
