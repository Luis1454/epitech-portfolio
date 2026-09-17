/*
** EPITECH PROJECT, 2021
** main.h
** File description:
** main include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct unit_s {
    int data;
    struct unit_s *prev;
    struct unit_s *next;
} unit_t;

typedef struct list_s {
    int len;
    unit_t *first;
    unit_t *last;
} list_t;

int is_empty(int *l2, int len);

int is_sorted(int *lst, int len);

int rev_rotate(int *l2, int len, int l, int i);

int rotate(int *l2, int len, int l);

int push_B(int *l1, int *l2, int len);

#endif    /* INCLUDE_H_ */
