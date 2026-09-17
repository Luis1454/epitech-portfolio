/*
** EPITECH PROJECT, 2022
** my_print_erno.c
** File description:
** print errno msg
*/

#include "../../include/my.h"
#include "../../include/handling.h"

static int sub_my_print_errno(int errno)
{
    display_errno_n(errno);
    display_errno_o(errno);
    display_errno_p(errno);
    display_errno_q(errno);
    display_errno_r(errno);
    display_errno_s(errno);
    display_errno_t(errno);
    display_errno_u(errno);
    display_errno_v(errno);
    display_errno_w(errno);
    display_errno_x(errno);
    display_errno_y(errno);
    display_errno_z(errno);
    display_errno_end(errno);
    return 0;
}

int my_print_errno(int errno)
{
    display_errno_a(errno);
    display_errno_b(errno);
    display_errno_c(errno);
    display_errno_d(errno);
    display_errno_e(errno);
    display_errno_f(errno);
    display_errno_g(errno);
    display_errno_h(errno);
    display_errno_i(errno);
    display_errno_j(errno);
    display_errno_k(errno);
    display_errno_l(errno);
    display_errno_m(errno);
    sub_my_print_errno(errno);
    return 0;
}
