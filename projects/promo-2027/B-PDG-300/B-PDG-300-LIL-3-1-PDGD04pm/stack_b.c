/*
** EPITECH PROJECT, 2024
** stack_b.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "stack.h"

void *stack_top(stack_t *stack)
{
    return stack->value;
}

void stack_clear(stack_t **stack_ptr)
{
    stack_t *tmp = *stack_ptr;

    while (tmp) {
        tmp = tmp->next;
        free(*stack_ptr);
        *stack_ptr = tmp;
    }
}
