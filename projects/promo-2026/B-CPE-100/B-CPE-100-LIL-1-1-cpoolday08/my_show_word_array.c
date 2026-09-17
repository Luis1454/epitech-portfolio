/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** display some words
*/

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        i++;
    }
    return 0;
}
