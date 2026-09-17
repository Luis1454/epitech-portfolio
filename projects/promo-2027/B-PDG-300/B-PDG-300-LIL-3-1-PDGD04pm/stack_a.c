/*
** EPITECH PROJECT, 2024
** stack_a.c
** File description:
** day 04 PM
*/

#include <stdlib.h>
#include "stack.h"

unsigned int stack_get_size(stack_t *stack)
{
    unsigned int i = 0;

    for (stack_t *tmp = stack; tmp; tmp = tmp->next)
        i++;
    return i;
}

bool stack_is_empty(stack_t *stack)
{
    return stack == NULL;
}

bool stack_push(stack_t **stack_ptr, void *elem)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = *stack_ptr;
    *stack_ptr = new;
    return true;
}

bool stack_pop(stack_t **stack_ptr)
{
    stack_t *tmp = *stack_ptr;

    if (tmp == NULL)
        return false;
    *stack_ptr = tmp->next;
    free(tmp);
    return true;
}
