/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my of h files
*/

#ifndef _MAIN_H
    #define _MAIN_H

int error_check(int ac, char **av);

char *par_rec(char *str, int p, int d, int e);

int adder(int k, int f);

int minner(int k, int f);

int multper(int k, int f);

int divver(int k, int f);

int modder(int k, int f);

char *int_to_str(int i);

char *int_to_str_neg(char *str, int i);

char *int_to_str_fix(char *str, int i);

int zero(char *av);

int check_number(char *av);

int sign_check(char av);

int error_checker(char **av);

char *do_op(char *num1, char *sign, char *num2, int i);

char *calculus(char *str);

char **tab_do_op(char * str);

void print_tab(char **tab);

int len_tab(char *str);

char **decale_tab(char *res, char **tab, int k);

char *calculus_k(char **tab, int k, char *res);

char *decale_plus(char *str, int k);

char *fix_expr(char *expr, char *b_num, char *b_op);

char *fix_end_expr(char *expr, char *b_num);

int *str_to_tab(char *str);

char *addition(char *first, char *second);

char *core(char *first, char *second);

int find_sign(char *str);

int bigger_str(char *first, char *second);

char *addition_tools(char *frst, char *secnd, char *res, int i);

char *resize(char *str, int len_b, int len_s);

int smaller_str(char *first, char *second);

char *smaller_str_2(char *first, char *second);

char *bigger_str_2(char *first, char *second);

char *add_str(char *res, char c);

char *decale(char *str);

int a_check(char *frst, char *secnd, int i);

char *fix_first(char *first, int i);

int error_fix(int c, char *str);

char *supp_neg(char *str);

char *addition_2(char *first, char *second);

char *soustraction(char *first, char *second);

char *soustraction_tools(char *frst, char *secnd, char *res, int i);

int s_check(char *frst, char *secnd, int i);

char *fix2_first(char *first, int i);

char *rem_str(char *str);

int check_neg(char *first, char *second);

int bigger_str_3(char *first, char *second);

void free_array(char **arr, int l1);

void get_array(char **arr, char *nb1, int len);

void get_mult(char **arr, char *nb1, char *nb2, int len);

void get_out(char **arr, char *out, char *nb1, char *nb2, int len);

char *mult(char *nb1, char *nb2);

#endif /* _MAIN_H */
