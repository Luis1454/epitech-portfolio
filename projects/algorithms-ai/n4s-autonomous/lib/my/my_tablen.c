/*
** EPITECH PROJECT, 2022
** mini shell  test
** File description:
** tablen.c
*/

#include "../../include/my.h"

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}
