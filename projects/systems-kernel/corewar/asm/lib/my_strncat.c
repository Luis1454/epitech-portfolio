/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strncat.c
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int length_dest = my_strlen(dest);
    int i = length_dest - my_strlen(src);
    int j = 0;

    for (; j < my_strlen(src) && j < nb; i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
