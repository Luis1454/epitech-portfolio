/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** check if a string is lower
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!('a' <= str[i] && str[i] <= 'z'))
            return 0;
    return 1;
}
