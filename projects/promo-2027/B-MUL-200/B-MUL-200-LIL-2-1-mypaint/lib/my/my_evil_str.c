/*
** EPITECH PROJECT, 2022
** my_evilstr.c
** File description:
** return the length of a string
*/

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    char tmp;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        tmp = str[my_strlen(str) - 1 - i];
        str[my_strlen(str) - 1 - i] = str[i];
        str[i] = tmp;
    }
    return str;
}
