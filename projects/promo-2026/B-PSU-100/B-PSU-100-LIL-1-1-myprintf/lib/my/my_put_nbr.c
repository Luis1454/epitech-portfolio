/*
** EPITECH PROJECT, 2021
** my_put_nmbr.c
** File description:
** task06
*/

void my_putchar(char c);

void check(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

void cut_number(int nb)
{
    char n;

    n = '0';
    if (nb) {
        n = (nb % 10) + '0';
        cut_number(nb / 10);
        my_putchar(n);
    }
}

int my_put_nbr(long long int nb)
{
    if (nb == -2147483648) {
        check();
    } else {
        if (!nb) {
            my_putchar('0');
            return 0;
        }
        if (nb < 0) {
            my_putchar('-');
            nb = -nb;
        }
        cut_number(nb);
    }
    return 0;
}
