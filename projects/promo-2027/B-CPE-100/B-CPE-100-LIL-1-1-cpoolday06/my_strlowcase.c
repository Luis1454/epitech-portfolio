/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** lowcase a string
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if ('A' <= str[i] && str[i] <= 'A')
            str[i] -= 32;
    return str;
}
