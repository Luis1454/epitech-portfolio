/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday03-mathis.zucchero
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int temp;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_put_nbr(-(nb / 10));
            return my_put_nbr(-(nb % 10));
        }
        return my_put_nbr(-nb);
    }
    if (nb > 9) {
        temp = nb % 10;
        my_put_nbr((nb - temp) / 10);
        my_putchar(temp + 48);
    } else {
        my_putchar(nb % 10 + 48);
    }
    return 0;
}
