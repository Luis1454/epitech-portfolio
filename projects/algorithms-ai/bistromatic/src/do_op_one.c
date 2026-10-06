/*
** EPITECH PROJECT, 2021
** do_op_one.c
** File description:
** First file of the do_op
*/

#include "../include/my.h"
#include "unistd.h"
#include "../include/main.h"

char *do_op(char *num1, char *sign, char *num2, int i)
{
    char *res;

    if (sign[0] == '*' || sign[0] == '/' || sign[0] == '%') {
        if (sign[0] == '*')
            res = mult(num1, num2);
        else if (sign[0] == '/') {
            i = divver(my_getnbr(num1), my_getnbr(num2));
            res = int_to_str(i);
        }
        else {
            i = modder(my_getnbr(num1), my_getnbr(num2));
            res = int_to_str(i);
        }
    }
    if (sign[0] == '+' || sign[0] == '-') {
        if (sign[0] == '+')
            res = core(num1, num2);
        else {
            i = minner(my_getnbr(num1), my_getnbr(num2));
            res = int_to_str(i);
        }
    }
    return res;
}

char *decale_plus(char *str, int k)
{
    if (str[k] == '-' && str[k +1] == '-') {
        str[k] = '+';
        for (int i = k + 1; str[i - 1]; i++) {
            str[i] = str[i + 1];
        }
    }
    return str;
}
