/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** structures include
*/

#pragma once

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t, ll_t;

typedef struct list {
    char *str;
    struct list *next;
} list_t;

linked_list_t *my_params_to_list(int ac, char * const *av);

int my_list_size(linked_list_t const *begin);

void my_rev_list(linked_list_t **begin);

int my_apply_on_nodes(linked_list_t *begin, int(* f)( void *));

int my_apply_on_matching_nodes(linked_list_t *begin,
int (*f)(void *), void const *data_ref, int (*cmp)(void const *, void const *));

int my_apply_on_nodes(linked_list_t *begin, int(* f)( void *));

linked_list_t *my_find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)(void const *, void const *));

linked_list_t *remove_node(linked_list_t *head,
linked_list_t *node, linked_list_t *prev);

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int(*cmp)(void const *, void const *));

linked_list_t *my_get_last_node(linked_list_t *begin);

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
