/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** task04
*/

char *my_evil_str(char *str)
{
    int i;
    while (*str != 0) {
        i++;
        str++;
    }

    char s[i];
    int j;
    for (j=0;j<i;j++) {
        s[j] = str[-j-1];
    }

    return s[0];
}
