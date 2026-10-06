/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copy a string
*/

int my_strlen(char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    if (i < my_strlen(dest))
        dest[i] = 0;
    return dest;
}
