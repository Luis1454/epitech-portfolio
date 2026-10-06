/*
** EPITECH PROJECT, 2024
** split.c
** File description:
** libstring split function
*/

#include <stdlib.h>
#include "string.h"

static int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++);
    return i;
}

char *get_word(char const *str, int *i, char separator)
{
    int j = 0;
    char *word = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; str[*i] && str[*i] != separator; (*i)++) {
        word[j] = str[*i];
        j++;
    }
    word[j] = 0;
    return word;
}

char **my_str_to_word_array(char const *str, char separator)
{
    int i = 0;
    int j = 0;
    char **tab = NULL;

    if (str == NULL)
        return NULL;
    tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
    if (tab == NULL)
        return NULL;
    for (; i < my_strlen(str); i++) {
        if (str[i] != separator) {
            tab[j] = get_word(str, &i, separator);
            j++;
        }
    }
    tab[j] = NULL;
    return tab;
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **arr = NULL;
    char **tab = NULL;
    int arrlen = 0;

    if (this == NULL || this->str == NULL)
        return NULL;
    tab = my_str_to_word_array(this->str, separator);
    if (tab == NULL)
        return NULL;
    for (; tab[arrlen]; arrlen++);
    arr = malloc(sizeof(string_t *) * (arrlen + 1));
    for (int i = 0; tab[i]; i++) {
        arr[i] = malloc(sizeof(string_t));
        string_init(arr[i], tab[i]);
    }
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    arr[arrlen] = NULL;
    return arr;
}

char **split_c(const string_t *this, char separator)
{
    char **tab = NULL;

    if (this == NULL || this->str == NULL)
        return NULL;
    tab = my_str_to_word_array(this->str, separator);
    return tab;
}
