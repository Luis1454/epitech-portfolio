/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** check if a string is a number
*/

int my_char_isnum(char c);

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isnum(str[i]))
            return 0;
    return 1;
}
