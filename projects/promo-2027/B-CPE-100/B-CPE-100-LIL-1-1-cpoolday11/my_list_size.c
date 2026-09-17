/*
** EPITECH PROJECT, 2022
** my_list_size.c
** File description:
** length of a linked list
*/

#include "include/my.h"
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    for (; begin != NULL; begin = begin->next, i++);
    return i;
}
