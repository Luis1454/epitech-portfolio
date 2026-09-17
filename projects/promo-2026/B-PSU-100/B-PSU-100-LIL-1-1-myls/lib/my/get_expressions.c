/*
** EPITECH PROJECT, 2021
** get_expressions.c
** File description:
** my_printf functions
*/

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

void my_putstr(char *str);

int my_put_nbr(int nb);

int my_strlen(char const *str);

int get_num_len(int num);

int pwr(int num, int pwr);

char *get_hex(unsigned int num, int state);

void my_put_sci(int nb, int state)
{
    int exp = 0;

    while (nb > 10){
        exp++;
        nb /= 10;
    }

    while (nb < 0.1) {
        exp--;
        nb *= 10;
    }

    my_put_nbr(nb);
    if (state)
        my_putstr("E+");
    else
        my_putstr("e+");

    my_put_nbr(exp);
}

char *int_to_str(int num)
{
    int n = get_num_len(num) - 1;
    char *str = malloc(sizeof(char *) * (n + 1));
    int len = get_num_len(num);

    for (int i = 0; i < len; i++) {
        str[i] = num / pwr(10, n);
        num -= (num / pwr(10, n)) * pwr(10, n);
        n--;
    }
    str[len - 1] = 0;

    return str;
}

void format_number(int num, int len)
{
    for (int i = 0; i < len - get_num_len(num); i++)
        my_putchar('0');
    my_put_nbr(num);
}

void print_unhandled(const char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (32 <= str[i] && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            format_number(str[i], 3);
        }
    }
}

void print_pointer(unsigned long long n)
{
    my_putstr("0x");
    my_putstr(get_hex(n, 0));
}
