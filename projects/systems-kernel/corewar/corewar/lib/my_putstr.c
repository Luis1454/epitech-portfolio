/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday04-mathis.zucchero
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        putchar_error(str[i]);
        i++;
    }
    return 0;
}
