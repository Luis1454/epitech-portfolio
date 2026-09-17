/*
** EPITECH PROJECT, 2022
** usage.c
** File description:
** usage functions for pushswap
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./pushswap -h\n");
    my_putstr("\t./pushswap [list of numbers]\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("\t-h\t\tprint the usage and quit\n");
    my_putstr("\t[list of numbers]\tlist of numbers to sort\n");
    return 0;
}
