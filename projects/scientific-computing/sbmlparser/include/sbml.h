/*
** EPITECH PROJECT, 2023
** sbml.h
** File description:
** SBML includes
*/

#include "mylist.h"

#ifndef SBML_H_
    #define SBML_H_

typedef struct args {
    char *var;
    char *value;
    struct args *next;
} args_t;

typedef struct node {
    int level;
    char *str;
    char *name;
    args_t *args;
    struct node *next;
} node_t;

int handle_products(node_t **b, char *id);

void swap_nodes(node_t *a, node_t *b);

void free_nodes(node_t *head);

void sort_node_by_var(node_t **head, char *var);

node_t *get_balises_from_str(char *str);

int get_name_pos(char *str);

int handle_e_flag(node_t *head, node_t *reaction);

int handle_i_flag(node_t *head, char *id, char *e_arg);

node_t *get_rectants(node_t **b);

int display_compartment(node_t *head, char *arg);

int handle_rectants(node_t **b, char *id);

int display_reaction(node_t *head, char *id, int e_flag, int json_flag);

int display_compound(node_t *head, char *id);

int check_reaction(node_t *head);

node_t *get_balise(node_t *head, char *balise, char *id);

char *get_arg(args_t *head, char *arg);

int sub_check_balise(node_t *tmp, char *balise, char *field, char *id);

int check_balise(node_t *head, char *id, char *balise, char *field);

args_t *get_args(char *str);

char *my_strdup_to(char const *src, char *to);

int get_first_alphanum(char *str);

int get_nb_args(args_t *head);

int is_in_lst(node_t *lst, char *str);

void append_ll_node(ll_t **head, char *str);

void append_node(node_t **head, char *str);

void skip_to_next_balise(int *i, char *str);

void sort_args(args_t **head);

void sort_node(node_t **head);

node_t *get_products(node_t **b);

int display_json_compound(node_t *head, char *id);

void sub_json_compound_a(node_t *head, node_t *node);

void sub_json_compound_b(node_t *head, char *id);

int handle_json_rectants(node_t **b);

int handle_json_products(node_t **b);

int is_last_node(node_t *node, char *balise, char *id);

#endif /* !SBML_H_ */
