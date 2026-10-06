/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** lowcase a string
*/

char my_charlowcase(char c)
{
    return 'A' <= c && c <= 'Z' ? c + 32 : c;
}

char my_charupcase(char c)
{
    return 'a' <= c && c <= 'z' ? c - 32 : c;
}

char *my_strlowcase(char *str, int confirm)
{
    if (!confirm)
        return str;
    for (int i = 0; str[i]; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
    return str;
}

int contain(const char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int str_contain(const char *a, const char *b)
{
    for (int i = 0; a[i]; i++)
        if (contain(b, a[i]))
            return 1;
    return 0;
}
