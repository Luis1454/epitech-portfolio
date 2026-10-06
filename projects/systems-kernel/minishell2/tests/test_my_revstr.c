/*
** EPITECH PROJECT, 2022
** test_my_revstr.c
** File description:
** tests for revstr
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *my_revstr(char *str);

Test (my_revstr, rev_classic_test)
{
    char str[] = "0123456789";

    cr_assert_str_eq(my_revstr(str), "9876543210");
}

Test (my_revstr, backslash_n_in_string)
{
    char str[] = "01234\n56789";

    cr_assert_str_eq(my_revstr(str), "98765\n43210");
}

Test (my_revstr, backslash_zero_in_string)
{
    char str[] = "01234056789";
    char oracle[] = "43210";

    str[5] = 0;
    cr_assert_str_eq(my_revstr(str), oracle);
}
