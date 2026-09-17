/*
** EPITECH PROJECT, 2021
** my_nbr_to_str.c
** File description:
** custom function
*/

char *my_revstr(char *str);

void my_putstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src);

int my_nbr_to_str(int nb, char *dest)
{
    char n[15];
    int i = 0;

    if (!nb || nb == -2147483648)
        return 0;
    while (nb) {
        n[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    n[i + 1] = 0;
    my_revstr(n);
    my_strcpy(dest, n);
    return 1;
}
