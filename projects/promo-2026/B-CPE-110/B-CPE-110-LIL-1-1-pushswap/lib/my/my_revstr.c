/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** task03
*/

#include "../../includes/my.h"

char *my_revstr(char *str)
{
    int count = 0;
    int temp_count = 0;
    char temp;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    temp_count = (count / 2);
    count--;
    for (int i = 0; i < temp_count; i++) {
        temp = str[i];
        str[i] = str[count];
        str[count] = temp;
        count--;
    }
}
