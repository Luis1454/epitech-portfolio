/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** pick up the words in a string
*/

#include "../../include/my.h"

static int skip_non_alphanum(char const *str, int i)
{
    for (; !(my_char_isalpha(str[i]) || my_char_isnum(str[i])) && str[i]; i++);
    return i;
}

static char **sub_word_array(char **out, char const *str, char *tmp, int n)
{
    for (int i = 0, nb = 0; i <= my_strlen(str); i++) {
        if (!(my_char_isalpha(str[i]) || my_char_isnum(str[i])) || !str[i]) {
            i = skip_non_alphanum(str, i);
            out[nb] = my_strdup(tmp);
            nb += !!my_strlen(tmp);
            n = 0;
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
