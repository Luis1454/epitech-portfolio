/*
** EPITECH PROJECT, 2021
** str_find.c
** File description:
** find a char into a string
*/

int my_strlen(char const *str);

int str_find(char const *str, char query)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == query)
            return 1;
    }
    return 0;
}
