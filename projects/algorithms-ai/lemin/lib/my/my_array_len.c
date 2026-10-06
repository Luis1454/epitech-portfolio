/*
** EPITECH PROJECT, 2023
** my_array_len
** File description:
** dsk
*/

#include "libmy.h"

int my_array_len(char **arr)
{
    int i = 0;
    for (; arr[i] != NULL; i++);
    return (i);
}
