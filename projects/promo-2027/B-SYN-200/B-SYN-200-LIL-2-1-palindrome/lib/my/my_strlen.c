/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** return the length of a string
*/

int my_strncmp(const char *s1, const char *s2, int n);

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

int my_strlen_to(const char *str, const char *to)
{
    int i = 0;

    if (!str || !to)
        return 0;
    for (; str[i] && my_strncmp(&str[i], to, my_strlen(to)); i++);
    return i;
}
