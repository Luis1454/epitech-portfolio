/*
** EPITECH PROJECT, 2024
** array_1d_to_2d.c
** File description:
** day 04
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    if (!array || !res)
        return;
    *res = malloc(sizeof(int *) * height);
    for (size_t i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * width);
        for (size_t j = 0; j < width; j++)
            (*res)[i][j] = array[i * width + j];
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++)
        if (array[i])
            free(array[i]);
    if (array)
        free(array);
}
