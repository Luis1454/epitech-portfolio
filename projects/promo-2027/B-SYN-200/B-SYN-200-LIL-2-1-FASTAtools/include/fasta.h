/*
** EPITECH PROJECT, 2023
** fasta.h
** File description:
** FASTA includes
*/

#include "mylist.h"

#ifndef FASTA_H_
    #define FASTA_H_

    char **my_arrdup(char **src);

    void free_arr(char **arr);

    int display_one(char **names, char **arr);

    int display_two(char **names, char **arr);

    int display_three(char **names, char **arr);

    int display_four(char **arr, int size);

    int start_by(char *str, char *pattern);

    int str_in_strs(char *str, char **to_find);

    int get_str_pos(char *str, char **pattern);

    int display_usage(void);

    char *my_strcapitalize_synthesis(char *str);

    void get_list(list_t **list, char **arr, int size);

    char **get_names(char *str, int len);

    int display_five(char **name, char **arr);

    void append_node(list_t **head, char *str);

    void sort_node(list_t **head);

#endif /* !FASTA_H_ */
