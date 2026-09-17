/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** display an array with linebreaks;
*/

#include "include/my.h"

int skip_non_alphanum(char const *str, int i)
{
    for (; !(my_char_isalpha(str[i]) || my_char_isnum(str[i])) && str[i]; i++);
    return i;
}

char **sub_word_array(char **out, char const *str, char *tmp, int n)
{
    for (int i = 0, nb = 0; str[i]; i++) {
        if (!(my_char_isalpha(str[i]) || my_char_isnum(str[i]))) {
            i = skip_non_alphanum(str, i);
            out[nb] = malloc(sizeof(char) * (n - 1));
            my_strcpy(out[nb], tmp);
            n = 0;
            nb++;
            out[nb] = 0;
        }
        tmp[n++] = str[i];
        tmp[n] = 0;
    }
    return out;
}

char **my_str_to_word_array(char const *str)
{
    char **out;
    int nb = 1;
    int n = 0;
    char *tmp;

    for (int i = 0; str[i]; i++)
        if (!(my_char_isalpha(str[i]) || my_char_isnum(str[i]))) {
            nb++;
            i = skip_non_alphanum(str, i);
        }

    tmp = malloc(sizeof(char) * my_strlen(str));
    out = malloc(sizeof(char *) * nb);
    out = sub_word_array(out, str, tmp, n);
    out[nb] = 0;

    return out;
}
