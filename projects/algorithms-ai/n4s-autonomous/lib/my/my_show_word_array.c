/*
** EPITECH PROJECT, 2022
** task 03
** File description:
** C pool day 08
*/

#include "../../include/my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return 0;
}
