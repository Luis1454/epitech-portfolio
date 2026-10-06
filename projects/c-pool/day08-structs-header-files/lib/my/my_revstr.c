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

    for (; str[n]; n++);
    n--;
    for (int i = 0; i <= n / 2; i++) {
        tmp = str[i];
        str[i] = str[n - i];
        str[n - i] = tmp;
    }
    return str;
}
