/*
** EPITECH PROJECT, 2021
** my_put_str.c
** File description:
** task05
*/

int my_getnbr(char const *str)
{
    int s = 0;
    int side = 1;
    int i = 0;

    while (!('0' < str[i] && str[i] < '9'))
        i++;

    for (i; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] != '+')
            side *= (-1);
    }
    for (i; str[i] && '0' <= str[i] && str[i] <= '9'; i++) {
        s *= 10;
        s += str[i] - 48;
    }
    s *= side;
    return s;
}
