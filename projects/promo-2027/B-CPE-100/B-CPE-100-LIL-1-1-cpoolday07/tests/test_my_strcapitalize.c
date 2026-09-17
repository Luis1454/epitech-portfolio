/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** tests for my_strcapitalize
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test (my_strcapitalize, basic_test)
{
    char dest[] = "hello world !";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hello World !");
}

Test (my_strcapitalize, complex_test)
{
    char dest[] = "hey, how are you? 42WORds forty-two; fifty+one";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test (my_strcapitalize, confirm_test)
{
    char dest[] = "hEy, HOW ARe yoU? 42WoRdS fOrTy-TwO; fIfTy+oNE";

    my_strcapitalize(dest);
    cr_assert_str_eq(dest, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}