/*
** EPITECH PROJECT, 2022
** test_my_revstr.c
** File description:
** tests for revstr
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test (rush, classic_test)
{
    char const *tab[] = {"./rush", "hello world", "h", "w"};

    cr_assert_eq(rush(4, tab), 0);
}

Test (rush, empy_test)
{
    char const *tab[] = {"./rush"};

    cr_assert_eq(rush(1, tab), 84);
}

Test (rush, zero_letter_test)
{
    char const *tab[] = {"./rush", "Space and time are relative."};

    cr_assert_eq(rush(2, tab), 0);
}

Test (rush, too_long_letter_test)
{
    char const *tab[] = {"./rush", "Space and time are relative.", "abcde"};

    cr_assert_eq(rush(3, tab), 84);
}
