/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file
*/

int my_strlen(char const *str);

int contain(char c, const char *lst)
{
    for (int i = 0; i < my_strlen(lst); i++)
        if (c == lst[i])
            return 1;
    return 0;
}
