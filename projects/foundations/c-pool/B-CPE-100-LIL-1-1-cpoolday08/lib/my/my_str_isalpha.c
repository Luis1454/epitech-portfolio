/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** check if a string is a text
*/

int my_char_isalpha(char c);

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isalpha(str[i]))
            return 0;
    return 1;
}
