/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_array_size.c
*/

#include <stddef.h>

int my_array_size(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
