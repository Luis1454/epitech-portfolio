/*
** EPITECH PROJECT, 2023
** common.c
** File description:
** common functions for ant and giant
*/

#include "../../include/my.h"
#include "../../include/antman.h"
#include "../../include/handling.h"

unsigned char *get_content(const char *file, unsigned long *size, char type)
{
    unsigned char *content = NULL;
    struct stat st;
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return NULL;
    stat(file, &st);
    content = malloc(sizeof(unsigned char) * (st.st_size + 1));
    if (content == NULL)
        return NULL;
    content[st.st_size] = 0;
    *size = st.st_size;
    read(fd, content, st.st_size);
    if (type == 'd' && st.st_size < content[0] * 2 + 3) {
        free(content);
        return NULL;
    }
    close(fd);
    return content;
}

node_t *add_node(node_t *head, byte_t byte)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return head;
    node->byte = byte;
    node->left = NULL;
    node->right = NULL;
    node->next = head;
    return node;
}

void free_tree(node_t *head)
{
    if (head == NULL)
        return;
    free_tree(head->left);
    free_tree(head->right);
    free(head);
}

node_t *create_tree(byte_t *arr, int len)
{
    node_t *head = NULL;

    for (int i = 0; arr[i].nb != -1; i++)
        head = add_node(head, arr[i]);
    head = heap_node(head, len);
    return head;
}
