/*
** EPITECH PROJECT, 2021
** my_list_size.c
** File description:
** return the size given a list
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av);

int my_list_size(linked_list_t *begin)
{
    struct linked_list *tmp;
    tmp = begin;
    int cnt = 0;

    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}
