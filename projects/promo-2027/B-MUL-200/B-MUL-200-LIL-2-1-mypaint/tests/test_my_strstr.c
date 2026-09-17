/*
** EPITECH PROJECT, 2022
** test_my_strstr.c
** File description:
** tests for strstr
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test (my_revstr, find_in_str_from_start_test)
{
    char str[] = "0123456789";

    cr_assert_str_eq(my_strstr(str, "0123"), "0123456789");
}

Test (my_revstr, find_in_str_test)
{
    char str[] = "0123456789";

    cr_assert_str_eq(my_strstr(str, "456"), "456789");
}

Test (my_revstr, find_in_str_out_of_range_test)
{
    char str[] = "0123456789";

    cr_assert_str_eq(my_strstr(str, "abc"), "0123456789");
}

Test (my_revstr, find_in_str_empty_test)
{
    char str[] = "0123456789";

    cr_assert_str_eq(my_strstr(str, ""), "0123456789");
}
