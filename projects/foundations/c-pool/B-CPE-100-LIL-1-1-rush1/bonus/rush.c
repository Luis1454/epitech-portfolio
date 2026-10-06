/*
** EPITECH PROJECT, 2022
** rush.c
** File description:
** bonus
*/

void my_putchar(char c);

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

int rush_generic(int x, int y, char *str)
{
    char h = my_strlen(str) >= 1 ? str[0] : '-';
    char v = my_strlen(str) >= 2 ? str[1] : '|';
    char a = my_strlen(str) >= 3 ? ((x > 1 && y > 1) ? str[2] : h) : 'o';
    char b = my_strlen(str) >= 4 ? ((x > 1 && y > 1) ? str[3] : h) : 'o';
    char c = my_strlen(str) >= 5 ? ((x > 1 && y > 1) ? str[4] : h) : 'o';
    char d = my_strlen(str) >= 6 ? ((x > 1 && y > 1) ? str[5] : h) : 'o';
    char empty = my_strlen(str) == 7 ? str[6] : ' ';

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            my_putchar((!i || i == x - 1) && (!j || j == y - 1) ?
            ((!i && !j) ? a : (i == x - 1 && !j) ? b :
            (i == x - 1 && j == y - 1) ? c : (i == x - 1 && !j) ? d : d):
            (!i || i == x - 1) ? h : (!j || j == y - 1) ? v : empty);
    my_putchar('\n');
    }
    return 0;
}

void rush(int x, int y)
{
    char pattern[] = "HVABCD.";

    if (x <= 0 || y <= 0)
        my_putstr("Invalid size\n");
    rush_generic(y, x, my_strlen(pattern) <= 7 ? pattern : "-|oooo");
    my_putchar('\n');
}
