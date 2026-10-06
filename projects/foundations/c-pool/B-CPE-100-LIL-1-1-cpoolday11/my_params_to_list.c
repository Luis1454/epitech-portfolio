/*
** EPITECH PROJECT, 2022
** my_params_to_list.c
** File description:
** sort params with a linked list
*/

#include "include/my.h"
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *node = NULL;
    linked_list_t *head = NULL;

    if (ac == 0)
        return (NULL);
    for (int i = 0; i < ac; i++) {
        node = malloc(sizeof(linked_list_t));
        node->data = av[i];
        node->next = head;
        head = node;
    }
    return node;
}
