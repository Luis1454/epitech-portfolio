/*
** EPITECH PROJECT, 2022
** stk.c
** File description:
** manage circular doubly linked list
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int remove_from_stk(stk **stack)
{
    stk *tmp = *stack;

    if (*stack == NULL)
        return 1;
    if ((*stack)->next == *stack) {
        free(*stack);
        *stack = NULL;
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        *stack = tmp->next;
        free(tmp);
    }
    return 0;
}

int push_to_stk(stk **stk_a, stk **stk_b, int side, int state)
{
    if (*stk_a == NULL)
        return 1;
    add_to_stk(stk_b, (*stk_a)->data);
    remove_from_stk(stk_a);
    if (!state)
        my_putchar(' ');
    my_putstr(side ? "pb" : "pa");
    return 0;
}

int reverse_stk(stk **stack)
{
    stk *tmp1 = *stack;
    stk *tmp2 = (*stack)->prev;
    int len = get_stk_size(*stack);

    if (*stack == NULL)
        return 1;
    for (int i = 0; i < len / 2; i++) {
        my_swap(&tmp1->data, &tmp2->data);
        tmp1 = tmp1->next;
        tmp2 = tmp2->prev;
    }
    return 0;
}

int add_to_stk(stk **stack, int data)
{
    stk *tmp = malloc(sizeof(stk));

    if (tmp == NULL)
        return 1;
    tmp->data = data;
    if ((*stack) != NULL) {
        tmp->next = *stack;
        tmp->prev = (*stack)->prev;
        if ((*stack)->prev != NULL)
            tmp->prev->next = tmp;
        (*stack)->prev = tmp;
    } else {
        tmp->prev = tmp;
        tmp->next = tmp;
    }
    *stack = tmp;
    return 0;
}

int create_stk(stk **stack, int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
        if (add_to_stk(stack, my_getnbr(argv[i]))) {
            print_error("Error while creating stk A\n");
            free_stk(*stack);
            return 84;
        }
    reverse_stk(stack);
    return 0;
}
