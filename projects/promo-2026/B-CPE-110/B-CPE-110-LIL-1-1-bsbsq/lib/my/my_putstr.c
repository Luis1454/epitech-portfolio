/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task02
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int count;

    count = 0;
    while (str[count] != 0) {
        my_putchar(str[count]);
        count++;
    }
    my_putchar('\n');
}
