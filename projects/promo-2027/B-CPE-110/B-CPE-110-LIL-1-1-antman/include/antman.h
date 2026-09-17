/*
** EPITECH PROJECT, 2022
** antman.h
** File description:
** antman include file
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

typedef struct byte_s {
    short c;
    int nb;
} byte_t;

typedef struct node_s {
    byte_t byte;
    struct node_s *next;
    struct node_s *left;
    struct node_s *right;
} node_t;

unsigned char *get_content(const char *file, unsigned long *size, char type);

void print_char_from_code(char *code, node_t *head, int size, int n);

void free_tree(node_t *head);

node_t *create_tree(byte_t *arr, int len);

byte_t *my_sort_array(byte_t *arr, int size);

byte_t *get_array(unsigned char *content, int size);

node_t *search_node(node_t *head, unsigned char c);

char **get_dictionary(byte_t *arr, node_t *node, int len);

node_t *heap_node(node_t *head, int len);

void display_arborescence(node_t *head, int level);

int get_nbr_from_chars(unsigned char *str, int min, int max, int block_size);

#endif /* ANTMAN_H_ */
