/*
** EPITECH PROJECT, 2022
** task 05
** File description:
** C pool day 05
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int i = 1;
    int result = 0;

    while (result < nb) {
        result = i * i;
        if (result == nb) {
            return i;
        }
        if (i > 46340) {
            return 0;
        } else {
            i = i + 1;
        }
    }
    return 0;
}
