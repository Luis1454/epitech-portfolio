/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcat.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int length_dest = my_strlen(dest);
    int i = (length_dest == 0 ? length_dest : length_dest - 1);
    int j = 0;

    for (; j < my_strlen(src); i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
