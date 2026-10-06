/*
** EPITECH PROJECT, 2023
** dict.c
** File description:
** dictionnary functions
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

char **init_dictionary(void)
{
    char **dict = NULL;

    dict = malloc(sizeof(char *) * 256);
    if (dict == NULL)
        return NULL;
    for (int i = 0; i < 256; i++) {
        dict[i] = malloc(sizeof(char) * 16);
        if (dict[i] == NULL)
            return NULL;
        for (int j = 0; j < 16; j++)
            dict[i][j] = 0;
    }
    return dict;
}

void sub_dict(char **dict, node_t *node, byte_t *arr, int i)
{
    node_t *tmp = node;
    int j = 0;

    for (j = 0; tmp->byte.c != arr[i].c; j++) {
        if (tmp->left && search_node(tmp->left, arr[i].c)) {
            dict[arr[i].c][j] = '0';
            tmp = tmp->left;
        } else {
            dict[arr[i].c][j] = '1';
            tmp = tmp->right;
        }
    }
    if (!j)
        dict[arr[i].c][j] = '1';
}

char **get_dictionary(byte_t *arr, node_t *node, int len)
{
    char **dict = init_dictionary();

    if (dict == NULL) {
        free_tree(node);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        sub_dict(dict, node, arr, i);
    }
    free_tree(node);
    return dict;
}
