/*
** EPITECH PROJECT, 2021
** tools.c
** File description:
** tools functions
*/

int max(int A, int B);

int my_strlen(char const *str);

int contain(char c, const char *lst)
{
    for (int i = 0; i < my_strlen(lst); i++)
        if (c == lst[i])
            return 1;
    return 0;
}

int are_equals(char *str, char *test)
{
    for (int i = 0; i < max(my_strlen(str), my_strlen(test)); i++)
        if (str[i] != test[i])
            return 0;
    return 1;
}
