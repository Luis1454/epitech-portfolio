/*
** EPITECH PROJECT, 2022
** my_atoi.c
** File description:
** my_atoi
*/

int my_atoi(const char *str)
{
    int nb = 0;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; '0' <= str[i] && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return (str[0] == '-') ? -nb : nb;
}
