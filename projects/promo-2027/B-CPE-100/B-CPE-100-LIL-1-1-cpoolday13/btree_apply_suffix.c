/*
** EPITECH PROJECT, 2022
** btree_apply_suffix.c
** File description:
** post-fix apply
*/

#include "include/btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
    if (root != NULL) {
        btree_apply_suffix(root->left, applyf);
        btree_apply_suffix(root->right, applyf);
        (*applyf)(root->item);
    }
}
