/*
** EPITECH PROJECT, 2021
** tools.c
** File description:
** tools file
*/

int my_strlen(char const *str);

char *my_strndup(char *str, int n);

int contain(char c, const char *lst)
{
    for (int i = 0; i < my_strlen(lst); i++)
        if (c == lst[i])
            return 1;
    return 0;
}

char *get_until_char(char *str, char c)
{
    int i;

    for (i = 0; str[i] != c; i++);

    if (str[i])
        return my_strndup(str, i);
    return str;
}
