/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** convert an lowercase string to uppercase
*/

int my_strlen(char *str);

char *my_strupcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (96 < str[i] && str[i] < 123)
            str[i] -= 32;
    return str;
}

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (65 < str[i] && str[i] < 89)
            str[i] += 32;
    return str;
}
