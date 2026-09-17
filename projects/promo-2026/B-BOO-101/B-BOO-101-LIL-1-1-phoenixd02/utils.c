/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** tools
*/

int my_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return len;
}

int get_nb_len(int nb)
{
    int i = 0;

    while (nb > 9) {
        nb /= 10;
        i++;
    }
    return i;
}
