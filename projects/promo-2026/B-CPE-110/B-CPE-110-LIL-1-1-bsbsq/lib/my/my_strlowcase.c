/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** task09
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (65 <= str[i] && str[i] <= 90)
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}
