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
    char h = 'B';
    char v = 'B';
    char a = (x > 1 && y > 1) ? 'A' : h;
    char b = (x > 1 && y > 1) ? 'C' : h;
    char c = (x > 1 && y > 1) ? 'A' : h;
    char d = (x > 1 && y > 1) ? 'C' : h;
    char empty = ' ';

    my_putchar((!i || i == x - 1) && (!j || j == y - 1) ?
    ((!i && !j) ? a : (i == x - 1 && !j) ? b :
    (i == x - 1 && j == y - 1) ? c : (i == x - 1 && !j) ? d : d) :
    (!i || i == x - 1) ? h : (!j || j == y - 1) ? v : empty);
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
