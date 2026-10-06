/*
** EPITECH PROJECT, 2022
** task 06
** File description:
** C pool day 04
*/

#include "../../include/my.h"

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int elmt;

    while (i < size - 1) {
        if (tab[i + 1] < tab[i]) {
            elmt = tab[i],
            tab[i] = tab[i + 1];
            tab[i + 1] = elmt;
            i = 0;
        } else {
            i++;
        }
    }
}
