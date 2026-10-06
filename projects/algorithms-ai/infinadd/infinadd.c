/*
** EPITECH PROJECT, 2021
** infinadd.c
** File description:
** infinite number adder
*/

#include <stdlib.h>
#include "include/my.h"

int check_syntax(const char *str)
{
    if (my_str_isnum(str) && str_find(str, '-'))
        return 1;
    else
        return 0;
}

void build_str(char const **argv, char *A, char *B, char *C, int len)
{
    for (int i = len - 1; i >= 0; i--) {
        if (*argv[1] == *argv[2] && *argv[1] == '-')
            i--;
        if (i < len - my_strlen(argv[1]))
            A[i] = 0;
        else
            A[i] = argv[1][i - (len - my_strlen(argv[1]))] - 48;
        if (i < len - my_strlen(argv[2]))
            B[i] = 0;
        else
            B[i] = argv[2][i - (len - my_strlen(argv[2]))] - 48;
        if (A[i]+B[i] < 10)
            C[i + 1] += A[i] + B[i];
        else {
            C[i + 1] += A[i] + B[i] - 10;
            C[i]++;
        }
    }
}

void print_result(char const **argv, char *A, char *B, char *C, int len)
{
    int j = 0;

    if (*A == *B && *B == '-')
        *C = 0;

    while (C[j] == 0)
        j++;

    if (*argv[1] == '-' && *argv[2] == '-')
        my_putchar('-');

    if (C == "\0")
        my_putchar('0');
    else {
        for (j; j < len + 1; j++)
            my_putchar(C[j] + 48);
    }

    my_putchar('\n');
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
        return 0;
    else if (check_syntax(argv[1]) || check_syntax(argv[2]))
        return 0;

    char *A;
    char *B;
    char *C;

    int len = max(my_strlen(argv[1]), my_strlen(argv[2]));

    A = malloc(len + 2 * sizeof(char));
    B = malloc(len + 2 * sizeof(char));
    C = malloc(len + 3 * sizeof(char));

    build_str(argv, A, B, C, len);

    print_result(argv, A, B, C, len);

    return 0;
}
