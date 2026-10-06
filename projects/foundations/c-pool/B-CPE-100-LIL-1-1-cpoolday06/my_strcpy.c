/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++)
    return i;
}

int my_const_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++)
    return i;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; i < src[i]; i++)
        dest[i] = src[i];
    if (i < my_strlen(dest))
        dest[i] = 0;
    return dest;
}
