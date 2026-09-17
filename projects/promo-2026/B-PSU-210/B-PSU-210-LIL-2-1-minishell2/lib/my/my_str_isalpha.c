/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** task01
*/

int is_alpha(const char *str)
{
    for (int i = 0; i < str[i]; i++)
        if (!(('a' <= str[i] && str[i] <= 'z')
        || ('A' <= str[i] && str[i] <= 'Z')))
            return 0;
    return 1;
}

int char_is_alpha(const char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
