/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && !(s1[i] - s2[i]); i++);
    return s1[i] - s2[i];
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] && s2[i] && !(s1[i] - s2[i]) && i < n; i++);
    if (n == i)
        return 0;
    return s1[i] - s2[i];
}
