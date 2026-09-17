/*
** EPITECH PROJECT, 2021
** my_nbr_to_str.c
** File description:
** custom function
*/

#include <stdlib.h>

char *my_memset(char *str, char c, int n);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_itoa(int nb, char *dest)
{
    int i = 0;
    if (!dest) {
        dest = malloc(sizeof(char) * 12);
        my_memset(dest, 0, 12);
    }
    if (!nb || nb == -2147483648) {
        my_strcpy(dest, "0");
        return dest;
    }
    for (; nb; nb /= 10, i++)
        dest[i] = (nb % 10) + '0';
    dest[i] = 0;
    my_revstr(dest);
    return dest;
}
