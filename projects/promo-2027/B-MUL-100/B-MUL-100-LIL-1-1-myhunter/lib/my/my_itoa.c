/*
** EPITECH PROJECT, 2021
** my_nbr_to_str.c
** File description:
** custom function
*/

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_itoa(int nb, char *dest)
{
    int i = 0;

    if (!nb || nb == -2147483648) {
        my_strcpy(dest, "0");
        return dest;
    }
    for (; nb; nb /= 10, i++)
        dest[i] = (nb % 10) + '0';
    dest[i] = 0;
    my_revstr(dest);
    return dest;
}
