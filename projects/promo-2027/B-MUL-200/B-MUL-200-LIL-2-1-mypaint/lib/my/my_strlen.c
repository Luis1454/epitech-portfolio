/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** return the length of a string
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}
