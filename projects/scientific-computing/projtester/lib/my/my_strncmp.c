/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compare two strings given a length
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return 0;
    for (; s1[i] && s2[i] && !(s1[i] - s2[i]) && i < n; i++);
    if (n == i)
        return 0;
    return s1[i] - s2[i];
}
