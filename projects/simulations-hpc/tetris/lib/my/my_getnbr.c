/*
** EPITECH PROJECT, 2021
** my_put_str.c
** File description:
** task05
*/

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;
    int i;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (i; str[i] && str[i] >= '0' && str[i] <= '9'; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    res *= sign;
    return res;
}
