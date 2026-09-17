/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** make a copy of a given string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i + 1] = 0;
    return dest;
}
