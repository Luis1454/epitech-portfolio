/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** check if a string is lower
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] == 127)
            return 0;
    return 1;
}
