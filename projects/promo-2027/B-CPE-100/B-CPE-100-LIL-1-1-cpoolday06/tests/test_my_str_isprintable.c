/*
** EPITECH PROJECT, 2022
** test_my_str_isalpha.c
** File description:
** tests for my_str_islpha
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test (my_str_isprintable, print_equals_test)
{
    char test[] = "l12f3!d04a56";

    cr_assert_eq(my_str_isprintable(test), 1);
}

Test (my_str_isprintable, print_not_equals_test)
{
    char test[] = "l12f3!d04a56";

    test[5] = 127;
    cr_assert_eq(my_str_isprintable(test), 0);
}

Test (my_str_isprintable, print_complex_test)
{
    char test[] = "l12f3!d04a56";

    test[5] = 1;
    cr_assert_eq(my_str_isprintable(test), 0);
}
