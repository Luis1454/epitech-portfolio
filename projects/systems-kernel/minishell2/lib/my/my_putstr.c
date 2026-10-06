/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** display strings
*/

int my_strlen(const char *str);

int my_putchar(char c);

int my_putstr(char const *str)
{
    if (!str) {
        my_putstr("(null)");
        return 0;
    }
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return my_strlen(str);
}
