/*
** EPITECH PROJECT, 2022
** my_rev_list.c
** File description:
** reverse a linked list
*/

#include "include/my.h"
#include "include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *node = *begin;
    linked_list_t *tmp = NULL;
    linked_list_t *next = NULL;
    while (node != NULL) {
        next = node->next;
        node->next = tmp;
        tmp = node;
        node = next;
    }
    (*begin)->next = NULL;
    (*begin) = tmp;
}
