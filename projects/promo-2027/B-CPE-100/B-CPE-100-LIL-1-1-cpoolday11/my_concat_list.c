/*
** EPITECH PROJECT, 2022
** my_concat_list.c
** File description:
** concatenate two linked lists
*/

#include "include/my.h"
#include "include/mylist.h"

linked_list_t *my_get_last_node(linked_list_t *begin)
{
    for (; begin->next != NULL; begin = begin->next);
    return begin;
}

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    my_get_last_node(*begin1)->next = begin2;
}
