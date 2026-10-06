/*
** EPITECH PROJECT, 2022
** pushswap.h
** File description:
** pushswap header
*/

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_

typedef struct stk {
    struct stk *prev;
    struct stk *next;
    int data;
} stk;

typedef struct range_s {
    int min;
    int max;
} Range, range;

int display_usage(void);

int free_stk(stk *stack);

int remove_from_stk(stk **stack);

int push_to_stk(stk **stk_a, stk **stk_b, int side, int state);

int add_to_stk(stk **stk, int data);

int check_stk(stk *stack);

int get_stk_size(stk *stack);

int create_stk(stk **stack, int argc, char const *argv[]);

int reverse_stk(stk **stack);

stk *get_node(stk *stack, int index);

int check_args(int argc, char const *argv[]);

int error_handling(int argc, char const *argv[]);

int rev_rotate_stk(stk **stack, int len, int side, int state);

int rotate_stk(stk **stack, int len, int side, int state);

int path_finder_rev_rotate(stk **stack, int dist, int state);

int path_finder_rotate(stk **stack, int dist, int state);

#endif /* PUSHSWAP_H_ */
