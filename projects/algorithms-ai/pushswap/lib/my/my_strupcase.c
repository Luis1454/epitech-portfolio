/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** upcase a string
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
    return str;
}
