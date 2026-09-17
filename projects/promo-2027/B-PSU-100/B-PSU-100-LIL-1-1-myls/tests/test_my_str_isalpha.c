/*
** EPITECH PROJECT, 2022
** test_my_str_isalpha.c
** File description:
** tests for my_str_islpha
*/

#include "../include/my.h"
#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test (my_str_isalpha, alpha_equals_test)
{
    cr_assert_eq(my_str_isalpha("abcdef"), 1);
}

Test (my_str_isalpha, alpha_not_equals_test)
{
    cr_assert_eq(my_str_isalpha("123456"), 0);
}

Test (my_str_isalpha, alpha_complex_test)
{
    cr_assert_eq(my_str_isalpha("l12f3!d4a56"), 0);
}
