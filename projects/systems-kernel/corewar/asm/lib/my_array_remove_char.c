/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_array_remove_char.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

char *set_array(char **array, char **new_array, int i, char c)
{
    int k = 0;
    int j = 0;
    for (; array[i][j] != '\0'; j++) {
        if (array[i][j] != c) {
            new_array[i][k] = array[i][j];
            k++;
        }
    }
    new_array[i][k] = '\0';
    return new_array[i];
}

char **my_array_remove_char(char **array, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **new_array = malloc(sizeof(char *) * (my_array_len(array) + 1));

    for (; array[i] != NULL; i++) {
        new_array[i] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
        new_array[i] = set_array(array, new_array, i, c);
    }
    new_array[i] = NULL;
    return new_array;
}
