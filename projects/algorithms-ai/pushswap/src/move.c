/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move functions
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int rev_rotate_stk(stk **stack, int len, int side, int state)
{
    stk *tmp = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return 1;
    for (int i = 0; i < len; i++) {
        my_putstr(state && !i ? "r" : " r");
        my_putstr(side ? "a" : "b");
        tmp = tmp->next;
    }
    *stack = tmp;
    return !len;
}

int rotate_stk(stk **stack, int len, int side, int state)
{
    stk *tmp = *stack;

    if (*stack == NULL || (*stack)->prev == NULL)
        return 1;
    for (int i = 0; i < len; i++) {
        my_putstr(state && !i ? "rr" : " rr");
        my_putstr(side ? "a" : "b");
        tmp = tmp->prev;
    }
    *stack = tmp;
    return !len;
}

int path_finder_rev_rotate(stk **stack, int dist, int state)
{
    int len = get_stk_size(*stack);

    if (dist > len / 2)
        state *= rotate_stk(stack, len - dist, 1, state);
    else
        state *= rev_rotate_stk(stack, dist, 1, state);
    return state;
}

int path_finder_rotate(stk **stack, int dist, int state)
{
    int len = get_stk_size(*stack);

    if (dist > len / 2)
        state *= rev_rotate_stk(stack, len - dist, 1, state);
    else
        state *= rotate_stk(stack, dist, 1, state);
    return state;
}
