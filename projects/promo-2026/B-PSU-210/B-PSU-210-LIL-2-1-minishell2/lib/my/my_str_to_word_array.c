/*
** EPITECH PROJECT, 2022
** my_str_to_word_array;
** File description:
** split a sentense in a 1D array
*/

#include <stdlib.h>
#include "../../includes/my.h"

int skip_char(char *str, char c, int i)
{
    for (; str[i] == c; i++);
    return i;
}

char *my_clear_str(char *str, char c)
{
    char *tmp = str;
    int n = 0;

    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == c) {
            str[n] = c;
            i = skip_char(tmp, c, i + 1);
            n++;
        }
        str[n] = 0;
    }
}

int get_len(char *str, char c)
{
    int len = 1;

    for (int i = 0; str[i]; i++)
        if (str[i] == c) {
            i = skip_char(str, c, i + 1);
            len++;
        }
    return len;
}

char **my_str_to_word_array(char *str, char c)
{
    int n = 0;
    int len = get_len(str, c);
    int cnt = 0;
    char **out = malloc(sizeof(char *) * (len + 1));
    int j;

    out[len] = NULL;
    for (int i = 0; i != len; i++) {
        for (n = 0; str[cnt + n] != c && str[cnt + n]; n++);
        out[i] = malloc(sizeof(char) * (n + 1));
        out[i][n] = 0;
        cnt += n + 1;
    }
    for (int i = 0, n = 0; out[i] != NULL; i++) {
        for (j = 0; str[n] != c && str[n]; j++, n++)
            out[i][j] = str[n];
        n++;
    }
    return out;
}
