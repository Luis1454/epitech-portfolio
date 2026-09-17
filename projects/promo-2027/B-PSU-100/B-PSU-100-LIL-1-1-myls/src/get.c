/*
** EPITECH PROJECT, 2021
** get.c
** File description:
** get functions
*/

#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/mylist.h"

int get_args(int *tab, char *arg, int is_flag)
{
    char flags[] = "aRrldt";

    for (int i = 1; arg[i]; i++) {
        if (is_flag && !contain(flags, arg[i]))
            return 1;
        if (is_flag)
            *(tab + (int)arg[i]) += 1;
    }
    return 0;
}

int get_id_array(int *arr, int size, int offset)
{
    for (int i = offset; i < size; i++)
        if (arr[i])
            return i;
    return -1;
}

int get_lower_time(char *str_a, char *str_b)
{
    struct stat a;
    struct stat b;

    stat(str_a, &a);
    stat(str_b, &b);
    if (a.st_mtime == b.st_mtime)
        return get_lower_str(str_a, str_b) < 0;
    return a.st_mtime < b.st_mtime;
}

int get_lower_str(char *A, char *B)
{
    int i = 0;

    for (; i < MIN(my_strlen(A), my_strlen(B)); i++) {
        if (A[i] != B[i])
            return my_charupcase(A[i]) - my_charupcase(B[i]);
    }
    return my_strlen(A) - my_strlen(B);
}

int get_sum_array(int *arr, int size, int offset)
{
    int out = 0;

    for (int i = offset; i < size; out += arr[i], i++);
    return out;
}
