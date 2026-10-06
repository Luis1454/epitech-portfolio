/*
** EPITECH PROJECT, 2022
** btree_search_item.c
** File description:
** search a btree node
*/

#include "include/btree.h"

void *btree_search_item(btree_t const *root,
void const *data_ref, int (*cmpf)(void const *, void const *))
{
    if (root != NULL && (*cmpf)(data_ref, root->item) > 0)
        btree_search_item(root->left, data_ref, cmpf);
    if (root != NULL && (*cmpf)(data_ref, root->item) < 0)
        btree_search_item(root->right, data_ref, cmpf);
    return (btree_t *)root;
}
