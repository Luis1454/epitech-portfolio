/*
** EPITECH PROJECT, 2022
** test_my_str_islower.c
** File description:
** tests for my_str_islpha
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test (my_str_islower, lower_equals_test)
{
    cr_assert_eq(my_str_islower("abcdef"), 1);
}

Test (my_str_islower, lower_not_equals_test)
{
    cr_assert_eq(my_str_islower("HJKSK"), 0);
}

Test (my_str_islower, lower_complex_test)
{
    cr_assert_eq(my_str_islower("HgJgjhHBHhgJJjjJtg"), 0);
}
