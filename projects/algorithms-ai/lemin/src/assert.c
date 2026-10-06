/*
** EPITECH PROJECT, 2023
** assert.c
** File description:
** assertion functions
*/

#include "lemin.h"

int all_args_are_digits(char **arr)
{
    for (int i = 0; arr[i]; i++)
        if (!my_str_is_numb(arr[i]))
            return 0;
    return 1;
}
