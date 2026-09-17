/*
** EPITECH PROJECT, 2022
** btree_apply_prefix.c
** File description:
** pre-fix apply
*/

#include "include/btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    if (root != NULL) {
        (*applyf)(root->item);
        btree_apply_prefix(root->left, applyf);
        btree_apply_prefix(root->right, applyf);
    }
}
