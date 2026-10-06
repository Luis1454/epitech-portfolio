/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** structures include
*/

#pragma once

union color {
    int rgba[4];
    int val;
};

struct info_param {
    int length;
    char *str;
    char *copy;
    char **word_array;
};

typedef struct triplet_t {
    int a;
    int b;
    int c;
} triplet;
