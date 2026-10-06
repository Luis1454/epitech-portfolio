/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy a string
*/

int my_strlen(char const *str);

void my_putchar(char c);

int my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
