/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main file for minishell1
*/

#include "../includes/include.h"
#include "../includes/my.h"
#include <stdlib.h>
#include <stdio.h>

int contain(char c, char *lst)
{
    for (int i = 0; i < my_strlen(lst); i++) {
        if (c == lst[i])
            return 1;
    }
    return 0;

}

void my_arr_cpy(char **dest, char **src)
{
    for (int i = 0; src; **src++, i++) {
        for (int j = 0; j < my_strlen(src[i]); j++)
            dest[i][j] = src[i][j];
        dest[i] = 0;
    }
}

int get_command(char *str)
{
    char arr[100][100];
    int j = 0;
    int k = 0;
    char lst[] = " \t\0\n";

    for (int i = 0; i < my_strlen(str); i++) {
        i += j;
        j = 0;
        while (contain(str[i], lst))
            i++;
        for (j; !contain(str[i + j], lst)
        && i + j  < my_strlen(str); j++) {
            arr[k][j] = str[i + j];
            arr[k][j + 1] = 0;
        }
        k++;
    }
    return **arr;
}

int main(int argc, char *argv[], char **env)
{
    int i = 0;
    char **table;

    return 0;
}
