/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils for palindrome
*/

#include "../include/my.h"
#include "../include/palindrome.h"

int str_is_in_array(char *str, char * const *arr)
{
    for (int i = 0; arr[i]; i++)
        if (!my_strcmp(str, arr[i]))
            return 1;
    return 0;
}

int check_args(int ac, char * const *av)
{
    char * const args[] = {"-n", "-p", "-b", "-imin", "-imax", NULL};

    if ((str_is_in_array("-n", av) && str_is_in_array("-p", av))
    || (!str_is_in_array("-n", av) && !str_is_in_array("-p", av)))
        return 1;
    for (int i = 1; i < ac; i++) {
        if ((i % 2 && av[i][0] != '-') || (!(i % 2) && av[i][0] == '-'))
            return 2;
        if (av[i][0] == '-' && !str_is_in_array(av[i], args))
            return 3;
        if ((av[i][0] != '-') && !my_str_isnum(av[i]))
            return 4;
        if (my_str_isnum(av[i]) && my_getnbr(av[i]) < 0)
            return 5;
    }
    return 0;
}

int get_base_len(int nb, int base)
{
    int len = 0;

    while (nb) {
        nb /= base;
        len++;
    }
    return len;
}

int get_rev_int(int nb, int base)
{
    int rev = 0;

    for (; nb; nb /= base)
        rev = rev * base + nb % base;
    return rev;
}

int check_values(core_t *core)
{
    if (core->n != -1 && core->p != -1)
        return 1;
    if (core->n != -1 && core->n < 0)
        return 2;
    if (core->p != -1 && core->p < 0)
        return 3;
    if (core->b < 2 || core->b > 10)
        return 4;
    if (core->imin < 0 || core->imax < 0)
        return 5;
    if (core->imin > core->imax)
        return 6;
    return 0;
}
