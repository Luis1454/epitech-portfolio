/*
** EPITECH PROJECT, 2022
** my_putadress
** File description:
** dsk
*/

#include "libmy.h"

void my_putadress(void *adress)
{
    my_putstr("0x");
    my_putnbr_base((long)adress, "0123456789abcdef");
}
