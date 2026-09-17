/*
** EPITECH PROJECT, 2022
** test_my_strcmp.c
** File description:
** tests for my_strcmp
*/

#include "../include/my.h"
#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test (my_strcmp, equals_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaaa";

    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}

Test (my_strcmp, differents_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaab";

    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}

Test (my_strcmp, size_and_differents_test)
{
    char str1[] = "aaaa";
    char str2[] = "aab";

    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}

Test (my_strcmp, backslash_zero_test)
{
    char str1[] = "aaaaaaaaaaaa";
    char str2[] = "aaaaaaaaaaab";

    str1[5] = 0;
    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}

Test (my_strcmp, size_and_equals_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaa";

    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}

Test (my_strcmp, full_random_test)
{
    char str1[] = "edjiuaesp";
    char str2[] = "ahdshqsdjdfkp";

    cr_assert_eq(my_strcmp(str1, str2), strcmp(str1, str2));
}
