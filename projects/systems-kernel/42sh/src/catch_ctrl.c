/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

void handler_ctrl(int sig)
{
    (void) sig;
    my_putstr("\n$> ");
}
