/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_deplace_array.c
*/

#include <stddef.h>

char **deplace_array2(char **array, int i, int j)
{
    for (; array[j] != NULL; j++) {
        array[j] = array[j + 1];
    }
    return array;
}

char **my_deplace_array(char **array)
{
    int i = 0;
    int j = 0;

    for (; array[i] != NULL; i++) {
        if (array[i][0] == '\0') {
            array = deplace_array2(array, i, j);
            i--;
        }
    }
    return array;
}
