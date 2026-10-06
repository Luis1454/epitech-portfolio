/*
** EPITECH PROJECT, 2022
** test_my_printf.c
** File description:
** tests for my_printf
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/handling.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

int my_printf(const char *format, ...);

Test (my_printf, pos_int_test, .init=redirect_all_stdout)
{
    my_printf("%i\n", 100);
    cr_assert_stdout_eq_str("100\n");
}

Test (my_printf, neg_int_test, .init=redirect_all_stdout)
{
    my_printf("%i\n", -100);
    cr_assert_stdout_eq_str("-100\n");
}

Test (my_printf, pos_digit_test, .init=redirect_all_stdout)
{
    my_printf("%d\n", 100);
    cr_assert_stdout_eq_str("100\n");
}

Test (my_printf, neg_digit_test, .init=redirect_all_stdout)
{
    my_printf("%d\n", -100);
    cr_assert_stdout_eq_str("-100\n");
}

Test (my_printf, pos_float_test, .init=redirect_all_stdout)
{
    my_printf("%f\n", 10.05);
    cr_assert_stdout_eq_str("10.050000\n");
}

Test (my_printf, neg_float_test, .init=redirect_all_stdout)
{
    my_printf("%f\n", -10.05);
    cr_assert_stdout_eq_str("-10.050000\n");
}

Test (my_printf, zero_float_test, .init=redirect_all_stdout)
{
    my_printf("%f\n", 0);
    cr_assert_stdout_eq_str("0.000000\n");
}

Test (my_printf, hole_float_test, .init=redirect_all_stdout)
{
    my_printf("%f\n", 10.0);
    cr_assert_stdout_eq_str("10.000000\n");
}

Test (my_printf, str_test, .init=redirect_all_stdout)
{
    my_printf("%s\n", "abc0123");
    cr_assert_stdout_eq_str("abc0123\n");
}

Test (my_printf, break_str_test, .init=redirect_all_stdout)
{
    my_printf("%s\n", "aaaa\0aaa");
    cr_assert_stdout_eq_str("aaaa\n");
}

Test (my_printf, null_str_test, .init=redirect_all_stdout)
{
    my_printf("%s\n", 0);
    cr_assert_stdout_eq_str("(null)\n");
}

Test (my_printf, low_hex_test, .init=redirect_all_stdout)
{
    my_printf("%x\n", 2);
    cr_assert_stdout_eq_str("2\n");
}

Test (my_printf, up_hex_test, .init=redirect_all_stdout)
{
    my_printf("%X\n", 299);
    cr_assert_stdout_eq_str("12B\n");
}

Test (my_printf, zero_hex_test, .init=redirect_all_stdout)
{
    my_printf("%X\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test (my_printf, neg_hex_test, .init=redirect_all_stdout)
{
    my_printf("%X\n", -1);
    cr_assert_stdout_eq_str("FFFFFFFF\n");
}

Test (my_printf, zero_octal_test, .init=redirect_all_stdout)
{
    my_printf("%o\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test (my_printf, neg_octal_test, .init=redirect_all_stdout)
{
    my_printf("%o\n", -1);
    cr_assert_stdout_eq_str("37777777777\n");
}

Test (my_printf, fivety_octal_test, .init=redirect_all_stdout)
{
    my_printf("%o\n", 50);
    cr_assert_stdout_eq_str("62\n");
}

Test (my_printf, alpha_char_test, .init=redirect_all_stdout)
{
    my_printf("%c\n", 'a');
    cr_assert_stdout_eq_str("a\n");
}

Test (my_printf, backslash_char_test, .init=redirect_all_stdout)
{
    my_printf("%c\n", '\\');
    cr_assert_stdout_eq_str("\\\n");
}

Test (my_printf, pos_num_char_test, .init=redirect_all_stdout)
{
    my_printf("%c\n", '0' + 5);
    cr_assert_stdout_eq_str("5\n");
}

Test (my_printf, empty_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", 0);
    cr_assert_stdout_eq_str("(nil)\n");
}

Test (my_printf, neg_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", -100);
    cr_assert_stdout_eq_str("0xffffff9c\n");
}

Test (my_printf, pos_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", 100000);
    cr_assert_stdout_eq_str("0x186a0\n");
}

Test (my_printf, long_overflow_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", (long)10e17);
    cr_assert_stdout_eq_str("0xde0b6b3a7640000\n");
}

Test (my_printf, neg_long_overflow_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", -(long)10e17);
    cr_assert_stdout_eq_str("0xf21f494c589c0000\n");
}

Test (my_printf, int_overflow_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", (int)10e9);
    cr_assert_stdout_eq_str("0x7fffffff\n");
}

Test (my_printf, neg_int_overflow_pointer_test, .init=redirect_all_stdout)
{
    my_printf("%p\n", -(int)10e9);
    cr_assert_stdout_eq_str("0x80000001\n");
}

Test (my_printf, pos_lowcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%b\n", 1);
    cr_assert_stdout_eq_str("true\n");
}

Test (my_printf, neg_lowcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%b\n", -1);
    cr_assert_stdout_eq_str("true\n");
}

Test (my_printf, zero_lowcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%b\n", 0);
    cr_assert_stdout_eq_str("false\n");
}

Test (my_printf, pos_upcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%B\n", 1);
    cr_assert_stdout_eq_str("TRUE\n");
}

Test (my_printf, neg_upcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%B\n", -1);
    cr_assert_stdout_eq_str("TRUE\n");
}

Test (my_printf, zero_upcase_boolean_test, .init=redirect_all_stdout)
{
    my_printf("%B\n", 0);
    cr_assert_stdout_eq_str("FALSE\n");
}

Test (my_printf, null_special_str_test, .init=redirect_all_stdout)
{
    my_printf("%S\n", 0);
    cr_assert_stdout_eq_str("(null)\n");
}

Test (my_printf, text_special_str_test, .init=redirect_all_stdout)
{
    my_printf("%S\n", "Hello World");
    cr_assert_stdout_eq_str("Hello World\n");
}

Test (my_printf, octal_special_str_test, .init=redirect_all_stdout)
{
    my_printf("%S\n", "player \001");
    cr_assert_stdout_eq_str("player \\001\n");
}

Test (my_printf, base_octal_special_str_test, .init=redirect_all_stdout)
{
    my_printf("%S\n", "player \177");
    cr_assert_stdout_eq_str("player \\177\n");
}

Test (my_printf, zero_unsigned_int_test, .init=redirect_all_stdout)
{
    my_printf("%u\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test (my_printf, pos_unsigned_int_test, .init=redirect_all_stdout)
{
    my_printf("%u\n", 1234);
    cr_assert_stdout_eq_str("1234\n");
}

Test (my_printf, neg_unsigned_int_test, .init=redirect_all_stdout)
{
    my_printf("%u\n", -1234);
    cr_assert_stdout_eq_str("4294966062\n");
}

Test (my_printf, overflow_pos_unsigned_int_test, .init=redirect_all_stdout)
{
    my_printf("%u\n", 100000000000000);
    cr_assert_stdout_eq_str("276447232\n");
}

Test (my_printf, overflow_neg_unsigned_int_test, .init=redirect_all_stdout)
{
    my_printf("%u\n", -100000000000000);
    cr_assert_stdout_eq_str("4018520064\n");
}

Test (my_printf, pos_hexa_lowcase_test, .init=redirect_all_stdout)
{
    my_printf("%x\n", 1234);
    cr_assert_stdout_eq_str("4d2\n");
}

Test (my_printf, neg_hexa_lowcase_test, .init=redirect_all_stdout)
{
    my_printf("%x\n", -1234);
    cr_assert_stdout_eq_str("fffffb2e\n");
}

Test (my_printf, pos_hexa_upcase_test, .init=redirect_all_stdout)
{
    my_printf("%X\n", 1234);
    cr_assert_stdout_eq_str("4D2\n");
}

Test (my_printf, neg_hexa_upcase_test, .init=redirect_all_stdout)
{
    my_printf("%X\n", -1234);
    cr_assert_stdout_eq_str("FFFFFB2E\n");
}

// test for float precision
Test (my_printf, float_dot_precision_test, .init=redirect_all_stdout)
{
    my_printf("%.2f\n", 1234.5678);
    cr_assert_stdout_eq_str("1234.57\n");
}

Test (my_printf, float_zero_dot_precision_test, .init=redirect_all_stdout)
{
    my_printf("%.0f\n", 1234.5678);
    cr_assert_stdout_eq_str("1235\n");
}

Test (my_printf, float_zero_precision_test, .init=redirect_all_stdout)
{
    my_printf("%0.0f\n", 1234.5678);
    cr_assert_stdout_eq_str("1235\n");
}

Test (my_printf, float_precision_test, .init=redirect_all_stdout)
{
    my_printf("%0.2f\n", 1234.5678);
    cr_assert_stdout_eq_str("1234.57\n");
}
