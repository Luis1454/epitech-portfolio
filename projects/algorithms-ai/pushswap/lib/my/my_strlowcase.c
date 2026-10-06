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

char *my_strlowcase(char *str, int confirm)
{
    if (confirm)
        return str;
    for (int i = 0; str[i]; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
    return str;
}
