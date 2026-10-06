/*
** EPITECH PROJECT, 2022
** star.c
** File description:
** star file
*/

void my_putchar(char c);

int my_putstr(char *str);

void display_two(void)
{
    my_putstr("   *\n");
    my_putstr("*** ***\n");
    my_putstr(" *   *\n");
    my_putstr("*** ***\n");
    my_putstr("   *\n");
}

void star_a(int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size * 3 - i - 1; j++)
            my_putchar(' ');
        my_putstr(i ? "*" : "");
        for (int j = 0; j < i * 2; j++)
            my_putstr(j ? " " : "");
        my_putstr("*\n");
    }
    for (int i = 0; i < size * 6 - 1; i++)
        my_putstr(2 * size < i && i < 4 * size - 2 ? " " : "*");
    my_putchar('\n');
}

void star_b(int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++)
            my_putchar(' ');
        my_putstr("*");
        for (int j = 0; j < size * 6 - i * 2 - 5; j++)
            my_putchar(' ');
        my_putstr("*\n");
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
            my_putchar(' ');
        my_putstr("*");
        for (int j = 0; j < size * 4 + i * 2 - 1; j++)
            my_putchar(' ');
        my_putstr("*\n");
    }
}

void star_c(int size)
{
    for (int i = 0; i < size * 6 - 1; i++)
        my_putstr(2 * size < i && i < 4 * size - 2 ? " " : "*");
    my_putchar('\n');
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size * 2 + i; j++)
            my_putchar(' ');
        my_putstr("*");
        for (int j = 0; j < size * 2 - i * 2 - 2; j++)
            my_putstr(j ? " " : "");
        my_putstr(i != size - 1 ? "*" : "");
        my_putchar('\n');
    }
}

void star(unsigned int size)
{
    if (size > 1) {
        star_a(size);
        star_b(size);
        star_c(size);
    } else if (size == 1)
        display_two();
}
