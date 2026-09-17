/*
** EPITECH PROJECT, 2021
** reverse_string.c
** File description:
** reverse a string
*/

int my_strlen(char *str);

char *reverse_string(char *str)
{
    int len = my_strlen(str);
    char tmp;

    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }

    return str;
}
