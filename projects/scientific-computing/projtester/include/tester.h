/*
** EPITECH PROJECT, 2023
** tester.h
** File description:
** tester includes
*/

#include <dirent.h>

#ifndef TESTER_H_
    #define TESTER_H_

    typedef struct list {
        char *name;
        struct list *next;
        struct list *child;
    } list_t;

    void free_array(char **array);

    void free_double(char *a, char *b);

    void free_tree(list_t *tree);

    void sort_tree(list_t **list);

    void display_tree(list_t *list, int depth);

    void append_node(list_t **list, char *name);

    int display_help(void);

    int failed_open(char *path);

    int run_tests(list_t *list, int ac, char **av, char *bin_path);

    int free_all(char **paths, int ret);

    char *get_env_path(char **env);

    char *get_last_element(char *str);

    list_t *get_node(list_t *list, char *name);

#endif /* !TESTER_H_ */
