/*
** EPITECH PROJECT, 2022
** btree_create_node.c
** File description:
** create a btree node
*/

#include "include/btree.h"

btree_t *btree_create_node(void *item)
{
    btree_t *node = malloc(sizeof(btree_t));

    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return node;
}
