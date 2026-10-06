/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** handle functions
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

int count_pipe(char **tab)
{
    int cp = 0;

    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '|')
            cp++;
    }
    return (cp);
}
