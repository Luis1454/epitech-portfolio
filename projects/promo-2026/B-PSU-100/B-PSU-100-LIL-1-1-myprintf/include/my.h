/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my of h files
*/

#include <stdarg.h>

#ifndef _MY_H
    #define _MY_H

void my_putchar(char c);

char *my_strstr(char *str, char const *to_find);

int my_isneg(int nb);

int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(long long int nb);

int my_strncmp(char const *s1, char const *s2, int n);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);

int my_putstr(char const *str);

char *my_strlowcase(char *str);

int my_strlen(char const *str);

char *my_strcapitalize(char *str);

int my_getnbr(char const *str);

int my_str_isalpha(char const *str);

void my_sort_int_array(int *tab, int size);

int my_str_isnum(char const *str);

int my_compute_power_rec(int nb, int power);

int my_str_islower(char const *str);

int my_compute_square_root(int nb);

int my_str_isupper(char const *str);

int my_is_prime(int nb);

int my_str_isprintable(char const *str);

int my_find_prime_sup(int nb);

int my_showstr(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_showmem(char const *str, int size);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strcat(char *dest, char const *src);

char *my_revstr(char *str);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char *str);

int min(int A, int B);

int max(int A, int B);

int pwr(int num, int pwr);

void my_put_sci(int nb, int state);

int get_num_len(int num);

void print_unhandled(const char *str);

int get_base(int num, int base);

char *get_hex(unsigned int num, int state);

void print_pointer(int n);

void place_value(const char *str, va_list lst, int i);

int my_printf(const char *str, ...);

#endif /* _MY_H */
