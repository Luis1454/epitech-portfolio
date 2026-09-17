/*
** EPITECH PROJECT, 2021
** strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;
    int len = 0;

    while (dest[len] && src[len]) {
        len++;
    }

    if (n > len)
        n = len;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }

    return dest;
}
