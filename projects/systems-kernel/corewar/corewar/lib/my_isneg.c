/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday03-mathis.zucchero
** File description:
** my_isneg.c
*/

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return 0;
}
