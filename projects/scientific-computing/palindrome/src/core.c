/*
** EPITECH PROJECT, 2023
** core.c
** File description:
** core functions
*/

#include "../include/my.h"
#include "../include/palindrome.h"
#include "../include/handling.h"

void init_default(core_t *core)
{
    core->n = -1;
    core->p = -1;
    core->b = 10;
    core->i = 0;
    core->imin = 0;
    core->imax = 100;
}

core_t *init_core(int ac, char * const *av)
{
    core_t *core = NULL;

    if (check_args(ac, av))
        return my_print_error("invalid argument\n") ? NULL : NULL;
    if (!(core = malloc(sizeof(core_t))))
        return NULL;
    init_default(core);
    for (int i = 1; i < ac; i++) {
        if (!my_strcmp(av[i], "-n"))
            core->n = my_getnbr(av[i + 1]);
        if (!my_strcmp(av[i], "-p"))
            core->p = my_getnbr(av[i + 1]);
        if (!my_strcmp(av[i], "-b"))
            core->b = my_getnbr(av[i + 1]);
        if (!my_strcmp(av[i], "-imin"))
            core->imin = my_getnbr(av[i + 1]);
        if (!my_strcmp(av[i], "-imax"))
            core->imax = my_getnbr(av[i + 1]);
    }
    return core;
}

int display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./palindrome -n number -p palindrome [-b base] [-imin i]");
    my_putstr(" [-imax i]\n\nDESCRIPTION\n");
    my_putstr("    -n n      integer to be transformed (>=0)\n");
    my_putstr("    -p pal    palindromic number to be obtained (incompatible");
    my_putstr(" with the -n option) (>=0)\n");
    my_putstr("    -b base   base in which the procedure will be executed ");
    my_putstr("(1<b<=10) [def: 10]\n");
    my_putstr("    -imin i   minimum number of iterations, included (>=0) ");
    my_putstr("[def: 0]\n");
    my_putstr("    -imax i   maximum number of iterations, included (>=0) ");
    my_putstr("[def: 100]\n");
    return 0;
}
