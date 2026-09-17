/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** task03
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

int my_utf_strlen(const char *str)
{
    int n = 0;
    int s = 0;

    for (int i = 0, v = 0; str[i]; i++, n++, v = 0) {
        for (; str[i] < 0; i++, v = 1);
        s += v * 3;
    }
    return n + s;
}
