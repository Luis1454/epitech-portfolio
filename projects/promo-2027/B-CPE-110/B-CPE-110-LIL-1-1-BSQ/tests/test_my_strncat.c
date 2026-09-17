/*
** EPITECH PROJECT, 2022
** test_my_strncat.c
** File description:
** tests for strcat
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *my_strncat(char *dest, char const *src, int nb);

Test (my_strncat, classic_test)
{
    char str1[100] = "01234";
    char str2[] = "56789";
    char *out = my_strncat(str1, str2, 50);

    cr_assert_str_eq(out, strncat(str1, str2, 50));
}

Test (my_strncat, avanced_test)
{
    char str1[] = "01234";
    char str2[] = "56789";
    char *out = my_strncat(str1, str2, 5);

    cr_assert_str_eq(out, strncat(str1, str2, 5));
}

Test (my_strncat, null_test)
{
    char str1[] = "01234";
    char str2[] = "56789";
    char *out = my_strncat(str1, str2, 0);

    cr_assert_str_eq(out, strncat(str1, str2, 0));
}

Test (my_strncat, void_test)
{
    char str1[10] = "01234";
    char str2[] = "1";
    char *out = my_strncat(str1, str2, 2);

    cr_assert_str_eq(out, strncat(str1, str2, 2));
}

Test (my_strncat, second_void_test)
{
    char str1[10] = "1";
    char str2[] = "lalala";
    char *out = my_strncat(str1, str2, 2);

    cr_assert_str_eq(out, strncat(str1, str2, 2));
}
