/*
** EPITECH PROJECT, 2022
** tests_my_put_nbr.c
** File description:
** custom tests
*/

int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(0);
    my_put_nbr(10);
    my_put_nbr(-84);
    my_put_nbr(42);
    my_put_nbr(1492);
    my_put_nbr(-8000);
    my_put_nbr(2147483647);
    my_put_nbr(-2147483648);

    return 0;
}
