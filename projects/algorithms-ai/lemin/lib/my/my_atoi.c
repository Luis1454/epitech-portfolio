/*
** EPITECH PROJECT, 2022
** my_atoi
** File description:
** dsk
*/

#include "libmy.h"

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            neg = neg * -1;
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nb = nb * 10 + (str[i] - '0');
    return (nb * neg);
}
