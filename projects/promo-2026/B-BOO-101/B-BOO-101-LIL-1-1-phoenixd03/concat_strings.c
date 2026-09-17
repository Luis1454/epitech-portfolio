/*
** EPITECH PROJECT, 2021
** concat_strings.c
** File description:
** concatenate two strings
*/

char *concat_strings(char *dest, char const *src)
{
    int off = my_strlen(src) + 1;
    int i;

    for (i = 0; i < my_strlen(dest); i++)
        dest[off + i] = src[i];
    dest[off + i + 1] = 0;
    return dest;
}
