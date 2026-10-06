/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** sort an int array
*/

int find_max(int *array, int size, int start)
{
    int id = 0;
    int max = array[id];

    for (int i = start; i < size; i++)
        if (array[i] > max) {
            max = array[i];
            id = i;
        }
    return id;
}

int find_min(int *array, int size, int start)
{
    int id = find_max(array, size, start);
    int min = array[id];

    for (int i = start; i < size; i++)
        if (array[i] < min) {
            min = array[i];
            id = i;
        }
    return id;
}

int swap_values(int *array, int a, int b)
{
    int tmp = array[a];

    array[a] = array[b];
    array[b] = tmp;

    return 0;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        swap_values(array, i, find_min(array, size, i));
}
