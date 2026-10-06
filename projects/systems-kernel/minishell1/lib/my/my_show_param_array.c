/*
** EPITECH PROJECT, 2022
** my_show_param_array.c
** File description:
** display the arguments infos
*/

#include "../../include/my.h"
#include "../../include/struct.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str && par[i].word_array; i++) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].length, __INT_MAX__);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
    }
    return 0;
}
