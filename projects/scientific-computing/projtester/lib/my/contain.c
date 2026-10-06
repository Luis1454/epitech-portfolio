/*
** EPITECH PROJECT, 2022
** contain.c
** File description:
** contain fonctions
*/

int contain(const char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int contain_str(const char *pattern, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (contain(pattern, str[i]))
            return 1;
    return 0;
}

int only_contain(const char *valid, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!contain(valid, str[i]))
            return 0;
    return 1;
}
