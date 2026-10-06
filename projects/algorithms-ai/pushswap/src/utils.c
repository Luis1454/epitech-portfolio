/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils functions
*/

#include "../include/my.h"
#include "../include/pushswap.h"
#include "../include/handling.h"

stk *get_node(stk *stack, int index)
{
    stk *tmp = stack;

    if (index < 0)
        return NULL;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp;
}

int get_stk_size(stk *stack)
{
    stk *tmp = stack;
    int i = 0;

    for (; stack != NULL && (!i || tmp != stack); i++)
        stack = stack->next;
    return i;
}

int check_args(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
        if (!my_str_isnum(argv[i])) {
            print_error("Invalid argument : ");
            my_putstr(argv[i]);
            my_putchar('\n');
            print_error("Try './pushswap -h' for more information\n");
            return 1;
        }
    return 0;
}

int error_handling(int argc, char const *argv[])
{
    return check_args(argc, argv);
}

int free_stk(stk *stack)
{
    stk *tmp = stack;
    int len = get_stk_size(stack);

    if (stack == NULL)
        return 1;
    for (int i = 0; i < len; i++) {
        stack = stack->next;
        free(tmp);
        tmp = stack;
    }
    return 0;
}
