/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return 0;
    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}
