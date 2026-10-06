/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my library
*/

#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

int count_valid_queens_placements(int n);

int my_compute_factorial_it(int nb);

int my_put_sci(double nb, char c);

int my_compute_factorial_rec(int nb);

int my_compute_power_it(int nb, int power);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

char *my_evil_str(char *str);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_getnbr_at(char *str, int i);

int my_isneg(int nb);

int my_is_prime(int nb);

int my_print_alpha(void);

int my_print_comb2(void);

int my_print_comb(void);

int my_print_combn(int n);

int my_print_digits(void);

int my_print_revalpha(void);

int my_put_nbr(long nb, unsigned long max);

int my_put_float(double nb, int quote, int fill, int round);

int my_putstr(char const *str);

char *my_revstr(char *str);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str, int confirm);

int my_put_unhandled(const unsigned char *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

int my_putchar(char c);

void my_swap(int *a, int *b);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_char_isnum(char c);

int my_char_isalpha(char c);

int my_show_word_array(char * const *tab);

char **my_str_to_word_array(char const *str);

char *my_strdup(char const *src);

char *concat_params(int argc, char **argv);

struct info_param *my_params_to_array(int ac, char **av);

int get_color(unsigned char red, unsigned char green, unsigned char blue);

long long my_normalize(long long nb);

int swap_endian_color(int color);

int get_unit(int n, int u);

char my_charlowcase(char c);

int rush(int ac, char const **av);

unsigned long my_getbase(long nb, long base);

char *my_strbase(unsigned long nb, long base, int is_upper);

unsigned long my_put_base(unsigned long nb, long base, char c);

int my_printf(const char *format, ...);

long double floor_float(long double nb, int n);

long double round_float(long double nb, int n);

int get_precision(int nb);

int calcul(double nb, char c);

int my_put_float(double nb, int quote, int fill, int round);

#endif /* MY_H_ */
