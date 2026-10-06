/*
** EPITECH PROJECT, 2022
** my_str_to_array.c
** File description:
** split a string as an array
*/

#include "../include/my.h"

int is_in_array(char *c, char **array)
{
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(c, array[i]))
            return 1;
    return 0;
}

static void skip_all_delim(char const *str, int *i, char *limit)
{
    for (; contain(limit, str[*i]) && str[*i]; (*i)++);
}

static char **sub_array(char **out, char const *str, char *limit, char *except)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int state = 1;

    if (!(tmp = my_memset(tmp, 0, my_strlen(str))))
        return NULL;
    for (int i = 0, n = 0, nb = 0; i <= my_strlen(str); i++) {
        if ((contain(limit, str[i]) && state) || !str[i]) {
            out[nb] = my_strdup(tmp);
            out[nb][0] = !my_strcmp(out[nb], "\n") ? 0 : out[nb][(n = 0)];
            nb += !!my_strlen(tmp);
            out[nb] = NULL;
            skip_all_delim(str, &i, limit);
        }
        state = contain(except, str[i])
        && (!i || str[i - 1] != '\\') ? !state : state;
        tmp[n++] = str[i];
        tmp[n] = 0;
    }
    free(tmp);
    return out;
}

char **my_str_to_array(char const *str, char *limit, char *except)
{
    char **out;
    int nb = 1;

    if (!str || !str[0] || contain(limit, 0))
        return NULL;
    for (int i = 0; i < my_strlen(str); i++) {
        nb += contain(limit, str[i]);
        skip_all_delim(str, &i, limit);
    }
    out = malloc(sizeof(char *) * (nb + 1));
    if (!out)
        return NULL;
    out = sub_array(out, str, limit, except);
    out[nb] = 0;

    return out;
}

int my_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}
