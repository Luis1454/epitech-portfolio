/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my library
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "../include/mylist.h"

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

char my_charupcase(char c);

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

double my_getfloat(const char *str);

double my_sqrt(double nb, int quote);

double my_atan(double nb);

double my_acos(double nb);

int is_sorted_list(read_list_t *node);

void swap_node(read_list_t *A, read_list_t *B);

void my_sort_list(read_list_t *head);

int display_asc(read_list_t *head, int *tab, int nb, int *format);

int display_list(read_list_t *head, int *tab, char *str, int *format);

void rev_read_list(read_list_t **begin);

int get_sum_array(int *arr, int size, int offset);

int get_id_array(int *arr, int size, int offset);

int *wrap(int a, int b);

int *wrap_3(int a, int b, int c);

int contain(const char *str, char c);

int get_lower_str(char *A, char *B);

int get_args(int *tab, char *arg, int is_flag);

char *my_weak_strcat(char *dest, char *src);

void my_sort_list(read_list_t *head);

int my_ls(char *str, int *tab, read_list_t *head, int skip_folders);

void my_sort_array(char *arr[], int size);

void sort_by_time(read_list_t *head);

int get_lower_time(char *str_a, char *str_b);

read_list_t *init_file(char *var);

void free_file(read_list_t *file);

char *my_memset(char *str, char c, int size);

int str_contain(const char *a, const char *b);

int format_list(char *str, int state);

char **my_str_to_array(char const *str, char *limit);

int only_contain(const char *valid, const char *str);

int find_out(const char *str, char c);

int my_print_error(char const *str);

int my_arrlen(char **arr);

int my_put_nbr_err(long nb, long max);

#endif /* MY_H_ */
