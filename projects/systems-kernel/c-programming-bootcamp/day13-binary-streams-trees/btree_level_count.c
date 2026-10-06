/*
** EPITECH PROJECT, 2022
** btree_level_count.c
** File description:
** count the max length of a btree
*/

#include "include/btree.h"

static size_t get_btree_len(btree_t const *node, size_t len)
{
    size_t a = 0;
    size_t b = 0;

    if (node == NULL)
        return len;
    a = get_btree_len(node->left, len + 1);
    b = get_btree_len(node->right, len + 1);
    return a > b ? a : b;
}

size_t btree_level_count(btree_t const * root)
{
    return get_btree_len(root, 1);
}
