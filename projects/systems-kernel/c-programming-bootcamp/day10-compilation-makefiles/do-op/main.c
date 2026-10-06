/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main file
*/

#include "../include/my.h"

int sub_main(int argc, char *argv[], int i, int out)
{
    int oracle = 1;

    if (*argv[i] == '+' && argc > i + 1 && oracle)
        oracle = my_put_nbr(out + my_getnbr(argv[i + 1]));
    if (*argv[i] == '-' && argc > i + 1 && oracle)
        oracle = my_put_nbr(out - my_getnbr(argv[i + 1]));
    if (*argv[i] == '*' && argc > i + 1 && oracle)
        oracle = my_put_nbr(out * my_getnbr(argv[i + 1]));
    if (*argv[i] == '/' && argc > i + 1 && oracle)
        oracle = my_put_nbr(out / my_getnbr(argv[i + 1]));
    if (*argv[i] == '%' && argc > i + 1 && oracle)
        oracle = my_put_nbr(out % my_getnbr(argv[i + 1]));
    return oracle;
}

int main(int argc, char const *argv[])
{
    int out;
    int oracle = 1;

    if (argc != 4)
        return 84;
    if (*argv[2] == '/' && !my_getnbr(argv[3])) {
        my_putstr("Stop: division by zero\n");
        return 0;
    } else if (*argv[2] == '%' && !my_getnbr(argv[3])) {
        my_putstr("Stop: modulo by zero\n");
        return 0;
    }
    out = my_getnbr(argv[1]);
    for (int i = 1; i < argc; i++) {
        oracle = sub_main(argc, argv, i, out);
    }
    my_putchar('\n');
    return 84 * oracle;
}
