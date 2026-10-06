/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** tests for my_strcapitalize
*/

#include "../include/my.h"
#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test (my_strcapitalize, capitalize_basic_test)
{
    char dest[] = "hello world !";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hello World !");
}

Test (my_strcapitalize, capitalize_complex_test)
{
    char dest[] = "hey, how are you? 42WORds forty-two; fifty+one";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test (my_strcapitalize, capitalize_confirm_test)
{
    char dest[] = "hEy, HOW ARe yoU? 42WoRdS fOrTy-TwO; fIfTy+oNE";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}
