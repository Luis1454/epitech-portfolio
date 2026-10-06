/*
** EPITECH PROJECT, 2023
** array.c
** File description:
** array functions
*/

#include "../include/fasta.h"
#include "../include/my.h"
#include <stdlib.h>

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        arr[i] ? free(arr[i]) : 0;
    arr ? free(arr) : 0;
}

void drop_arr(char ***arr, int i)
{
    char **tmp = my_arrdup(*arr);
    int n = 0;

    if (!tmp)
        return;
    free_arr(*arr);
    *arr = malloc(sizeof(char *) * (my_arrlen(tmp) + 1));
    if (!*arr)
        return free_arr(tmp);
    for (int j = 0; tmp[j]; j++)
        if (j != i)
            (*arr)[n++] = my_strdup(tmp[j]);
    (*arr)[my_arrlen(tmp)] = NULL;
    free_arr(tmp);
}

int count_chars(char *str, char c)
{
    int n = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            n++;
    return n;
}

void swap_str(char **str1, char **str2, int assert)
{
    if (!assert)
        return;
    char *tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void sort_node(list_t **head)
{
    for (list_t *tmp = *head; tmp; tmp = tmp->next)
        for (list_t *tmp2 = tmp->next; tmp2; tmp2 = tmp2->next)
            swap_str(&tmp->str, &tmp2->str, my_strcmp(tmp->str, tmp2->str) > 0);
}
