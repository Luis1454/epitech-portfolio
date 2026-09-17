/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** display strings
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
