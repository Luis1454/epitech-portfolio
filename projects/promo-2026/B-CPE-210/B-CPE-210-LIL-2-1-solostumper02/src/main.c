/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** stumpers subject
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int main(int argc, char *argv[])
{
    char usage[] = "Usage: ./hidenp needle haystack\n";
    char out[3] = "0\n";
    int j = 0;
    int v;

    if (argc != 3) {
        write(1, &usage, my_strlen(usage));
        return 84;
    }
    for (int i = 0; i < my_strlen(argv[2]); i++)
        if (argv[1][j] == argv[2][i])
            j++;
    v = 48 + (j == my_strlen(argv[1]));
    out[0] = v;
    write(1, &out, 2);
    return 0;
}
