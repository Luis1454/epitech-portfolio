/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-alexis.salaun
** File description:
** check_file_error_handling.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"
#include "../include/handling.h"

int check_handling(char *str)
{
    if (str == NULL)
        return 1;
    if (!only_contain("0123456789, -\n", str)) {
        my_print_error("Invalid character in map file (only numbers, spaces");
        my_print_error(", commas, dashes and \\n are allowed)\n");
        free(str);
        return 2;
    }
    return 0;
}
