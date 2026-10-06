/*
** EPITECH PROJECT, 2022
** btree_insert_data.c
** File description:
** create a btree node
*/

#include "include/btree.h"

void btree_insert_data(btree_t **root, void *item, int (*cmpf)(void const *, void const *))
{
    if ((*root) != NULL) {
        if ((*cmpf)(item, (*root)->item) < 0)
            btree_insert_data(&((*root)->left), item, cmpf);
        else
            btree_insert_data(&((*root)->right), item, cmpf);
    }
    (*root) = btree_create_node(item);
}
