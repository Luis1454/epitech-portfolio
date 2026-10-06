/*
** EPITECH PROJECT, 2022
** test_my_my_strncmp.c
** File description:
** tests for my_strncmp
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test (my_strncmp, equals_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaaa";

    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}

Test (my_strncmp, differents_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaab";

    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}

Test (my_strncmp, size_and_differents_test)
{
    char str1[] = "aaaa";
    char str2[] = "aab";

    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}

Test (my_strncmp, backslash_zero_test)
{
    char str1[] = "aaaaaaaaaaaa";
    char str2[] = "aaaaaaaaaaab";

    str1[5] = 0;
    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}

Test (my_strncmp, size_and_equals_test)
{
    char str1[] = "aaaa";
    char str2[] = "aaa";

    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}

Test (my_strncmp, full_random_test)
{
    char str1[] = "edjiuaesp";
    char str2[] = "ahdshqsdjdfkp";

    cr_assert_eq(my_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}


Test (my_strncmp, void_random_test)
{
    char str1[] = "edjiuaesp";
    char str2[] = "ahdshqsdjdfkp";

    cr_assert_eq(my_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}

Test (my_strncmp, limit_random_test)
{
    char str1[] = "edjiuaesp";
    char str2[] = "ahdshqsdjdfkp";

    cr_assert_eq(my_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
