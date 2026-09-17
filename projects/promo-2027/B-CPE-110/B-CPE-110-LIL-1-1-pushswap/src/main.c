/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** bsq main file
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

range get_lower(stk *stk_a, int len, int last, int use_last)
{
    stk *tmp = stk_a;
    int min = tmp->data;
    int n = 0;
    int is_next = 0;

    for (int i = 0; i < len; i++) {
        if (tmp->data == last + 1 && !is_next)
            is_next = 1;
        if (use_last && tmp->data == last)
            return (range){i, 1};
        if (tmp->data < min) {
            min = tmp->data;
            n = i;
        }
        tmp = tmp->next;
    }
    return ((range){n, 1});
}

void sort_stk(stk **stk_a, stk **stk_b, int state, int len)
{
    int nb = 0;
    Range r = get_lower(*stk_a, len, 0, 0);
    int last = r.min;
    int n = last;
    int i = 0;

    while (nb < len) {
        if (i) {
            r = get_lower(*stk_a, len - nb, last, 1);
            n = r.min;
        }
        state = path_finder_rev_rotate(stk_a, n, state);
        state = push_to_stk(stk_a, stk_b, 1, state);
        last = (*stk_b)->data;
        nb += 1 + !r.max;
        i++;
    }
    for (int i = 0; i < len; i++)
        state = push_to_stk(stk_b, stk_a, 0, state);
}

int pushswap(int argc, char const *argv[])
{
    stk *stk_a = NULL;
    stk *stk_b = NULL;

    if (error_handling(argc, argv) || create_stk(&stk_a, argc, argv))
        return 84;
    sort_stk(&stk_a, &stk_b, 1, argc - 1);
    my_putchar('\n');
    free_stk(stk_a);
    free_stk(stk_b);
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
        return 0;
    if (argc == 2 && (!my_strcmp(argv[1], "-h")
    || !my_strcmp(argv[1], "--help")))
        return display_usage();
    return pushswap(argc, argv);
}
