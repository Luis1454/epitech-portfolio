/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** returns the difference between two string lengths
*/

int my_strlen(char *str);

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n > max(my_strlen(s1), my_strlen(s2)))
        return my_strlen(s1) - my_strlen(s2);
    return 0;
}
