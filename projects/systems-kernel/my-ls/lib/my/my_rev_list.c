/*
** EPITECH PROJECT, 2022
** my_rev_list.c
** File description:
** reverse a linked list
*/

#include "../../include/my.h"
#include "../../include/mylist.h"

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

void swap_node(read_list_t *A, read_list_t *B)
{
    struct dirent *tmp = A->data;

    if (A != NULL && B != NULL) {
        A->data = B->data;
        B->data = tmp;
    }
}

void rev_read_list(read_list_t **begin)
{
    read_list_t *node = *begin;
    read_list_t *tmp = NULL;

    while (node != NULL) {
        tmp = node->prev;
        node->prev = node->next;
        node->next = tmp;
        node = node->prev;
    }
    if (tmp)
        *begin = tmp->prev;
}
