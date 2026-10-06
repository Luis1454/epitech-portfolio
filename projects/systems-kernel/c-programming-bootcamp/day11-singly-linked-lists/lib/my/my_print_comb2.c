/*
** EPITECH PROJECT, 2022
** my_print_comb2.c
** File description:
** print some ascending numbers
*/

int my_putstr(char *str);

void my_putchar(char c);

int get_unit(int n, int u);

int my_print_comb2(void)
{
    int j = 0;

    for (int i = 0; j < 99; i++) {
        for (; i >= 100; i = 0, j++);
        if (i > j) {
            my_putchar(get_unit(j, 100) + '0');
            my_putchar(get_unit(j, 10) + '0');
            my_putchar(' ');
            my_putchar(get_unit(i, 100) + '0');
            my_putchar(get_unit(i, 10) + '0');
            j != 98 && i ? my_putstr(", ") : 0;
        }
    }
    my_putchar('\n');
    return 0;
}
