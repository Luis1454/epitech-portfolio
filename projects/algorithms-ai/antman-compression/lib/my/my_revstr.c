/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int n = 0;
    char tmp;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        tmp = str[i];
        str[i] = str[my_strlen(str) - i - 1];
        str[my_strlen(str) - i - 1] = tmp;
    }
    return str;
}
