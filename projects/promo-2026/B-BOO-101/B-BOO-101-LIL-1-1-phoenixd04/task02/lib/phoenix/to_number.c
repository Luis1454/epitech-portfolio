/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** char to int converter
*/

int to_number(char const *str)
{
    int i = 0;
    int side = 1;
    int out = 0;

    while ('0' < str[i] && str[i] > '9' && str[i] != '+' && str[i] != '-')
        i++;
    for (i; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            side *= -1;
    for (i; '0' <= str[i] && str[i] <= '9' && str[i]; i++) {
        out *= 10;
        out += str[i] - '0';
    }
    out *= side;
    return out;
}
