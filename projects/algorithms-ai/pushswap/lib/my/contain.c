/*
** EPITECH PROJECT, 2022
** contain.c
** File description:
** contain fonctions
*/

int contain(char c, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int only_contain(const char *valid, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!contain(str[i], valid))
            return 0;
    return 1;
}
