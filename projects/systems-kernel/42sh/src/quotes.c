/*
** EPITECH PROJECT, 2023
** quotes.c
** File description:
** quote handling
*/

#include "../include/my.h"
#include "../include/minishell.h"
#include "../include/my_macro_abs.h"

void check_reverse_quote(char **str)
{
    char *tmp = NULL;
    int size = MAX(my_strlen(*str), 2) * 2 - 4 + 1;

    if (!(*str) || (*str)[0] != '\'' || (*str)[my_strlen(*str) - 1] != '\'')
        return;
    if (!(tmp = malloc(sizeof(char) * size)))
        return;
    tmp = my_memset(tmp, 0, size);
    for (int i = 0; i < my_strlen(*str); i++) {
        i += ((*str)[i] == '\'' && (!i || (i && (*str)[i - 1] != '\\')));
        if ((*str)[i] == '"' && (*str)[i - 1] != '\\')
            tmp = my_strcat(tmp, "\\");
        tmp = my_strncat(tmp, &(*str)[i], 1);
    }
    free(*str);
    *str = tmp;
}

int format_split(char **split, int len, char c)
{
    char s[] = {c, 0};

    for (int i = 0; i < len; i++) {
        check_reverse_quote(&(split[i]));
        if (count_char(split[i], c) % 2) {
            my_print_error("Unmatched '");
            my_print_error(s);
            my_print_error("'.\n");
            return 1;
        }
    }
    return 0;
}
