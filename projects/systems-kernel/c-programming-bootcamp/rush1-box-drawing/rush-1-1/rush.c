/*
** EPITECH PROJECT, 2022
** rush.c
** File description:
** rush1
*/

void my_putchar(char c);

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}

int sub_rush(int i, int j, int x, int y)
{
    my_putchar((!i || i == x - 1) && (!j || j == y - 1) ? 'o' :
    (!i || i == x - 1) ? '-' : (!j || j == y - 1) ? '|' : ' ');
    return 0;
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0)
        my_putstr("Invalid size\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            sub_rush(i, j, y, x);
        my_putchar('\n');
    }
}
