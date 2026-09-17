/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** check if a string is upper
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!('A' <= str[i] && str[i] <= 'Z'))
            return 0;
    return 1;
}
