/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib test
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (!(47 < str[i] && str[i] < 58))
            return 0;
    }
    return 1;
}
