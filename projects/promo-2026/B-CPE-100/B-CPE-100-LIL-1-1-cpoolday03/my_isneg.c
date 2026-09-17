/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
**
*/

#include <unistd.h>

int my_isneg(int n)
{
    if(n < 0)
    {
        write(1, "N\n", 2);
    }else{
        write(1, "P\n", 2);
    }
    return 0;
}
