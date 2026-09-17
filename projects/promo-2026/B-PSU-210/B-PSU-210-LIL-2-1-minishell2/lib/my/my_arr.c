/*
** EPITECH PROJECT, 2021
** my_arr.c
** File description:
** functions for arrays
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(const char *str);

int my_putchar(char c);

void my_arr_cpy(char **dest, char **src)
{
    for (int i = 0; src[i] != NULL; i++) {
        for (int j = 0; j < my_strlen(src[i]); j++)
            dest[i][j] = src[i][j];
        dest[i] = 0;
    }
}

int my_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return i;
}

void free_str_arr(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

void read_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j]; j++)
            my_putchar(arr[i][j]);
        my_putchar('\n');
    }
}
