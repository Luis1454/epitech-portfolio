/*
** EPITECH PROJECT, 2024
** string.h
** File description:
** string includes
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef STRING_H_
    #define STRING_H_

typedef struct string_s {
    char *str;

    void (*append_s)(struct string_s *this, const struct string_s *ap);

    void (*append_c)(struct string_s *this, const char *ap);

    int (*length)(struct string_s *this);

    void (*assign_s)(struct string_s *this, const struct string_s *str);

    void (*assign_c)(struct string_s *this, const char *s);

    char (*at)(struct string_s *this, size_t pos);

    void (*clear)(struct string_s *this);

    int (*compare_s)(struct string_s *this, const struct string_s *str);

    int (*compare_c)(struct string_s *this, const char *str);

    size_t (*copy)(struct string_s *this, char *s, size_t n, size_t pos);

    char *(*c_str)(struct string_s *this);

    int (*empty)(struct string_s *this);

    int (*find_s)(struct string_s *this, const struct string_s *str,
        size_t pos);

    int (*find_c)(struct string_s *this, const char *str, size_t pos);

    void (*insert_c)(struct string_s *this, size_t pos, const char *str);

    void (*insert_s)(struct string_s *this, size_t pos,
        const struct string_s *str);

    int (*to_int)(struct string_s *this);

    struct string_s **(*split_s)(struct string_s *this, char separator);

    char **(*split_c)(struct string_s *this, char separator);

    void (*print)(struct string_s *this);

} string_t;

void string_init(string_t *this, const char *s);

void append_s(string_t *this, const string_t *ap);

void append_c(string_t *this, const char *ap);

void string_destroy(string_t *this);

void assign_s(string_t *this, const string_t *str);

void assign_c(string_t *this, const char *s);

char at(const string_t *this, size_t pos);

void clear(string_t *this);

int compare_s(const string_t *this, const string_t *str);

int compare_c(const string_t *this, const char *str);

size_t copy(const string_t *this, char *s, size_t n, size_t pos);

const char *c_str(const string_t *this);

int empty(const string_t *this);

int find_s(const string_t *this, const string_t *str, size_t pos);

int find_c(const string_t *this, const char *str, size_t pos);

void insert_c(string_t *this, size_t pos, const char *str);

void insert_s(string_t *this, size_t pos, const string_t *str);

int to_int(const string_t *this);

string_t **split_s(const string_t *this, char separator);

char **split_c(const string_t *this, char separator);

void print(const string_t *this);

int length(const string_t *this);

#endif /* !STRING_H_ */
