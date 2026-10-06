/*
** EPITECH PROJECT, 2022
** task 05
** File description:
** C pool day 04
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int nb_negatif = 1;
    int power = 0;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            nb_negatif *= -1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * power + (str[i] - '0');
            power = 10;
        }
    }
    return nb * nb_negatif / 10;
}
