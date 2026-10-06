/*
** EPITECH PROJECT, 2022
** test_my_strcat.c
** File description:
** tests for strcat
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *my_strcat(char *dest, char const *src);

Test (my_strcat, classic_test)
{
    char str1[20] = "01234";
    char str2[] = "56789";
    char *out = my_strcat(str1, str2);

    cr_assert_str_eq(out, "0123456789");
}

Test (my_strcat, avanced_test)
{
    char str1[] = "01234";
    char str2[] = "56789";
    char *out = my_strcat(str1, str2);

    cr_assert_str_eq(out, "0123456789");
}

Test (my_strcat, newline_test)
{
    char str1[] = "01234";
    char str2[] = "56\n789";
    char *out = my_strcat(str1, str2);

    cr_assert_str_eq(out, "0123456\n789");
}

Test (my_strcat, break_test)
{
    char str1[] = "01 234";
    char str2[] = "56 789";
    char *out = my_strcat(str1, str2);

    cr_assert_str_eq(out, "01 23456 789");
}
