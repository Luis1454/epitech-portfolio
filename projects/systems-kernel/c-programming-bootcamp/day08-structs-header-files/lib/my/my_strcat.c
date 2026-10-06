/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; i < src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}
