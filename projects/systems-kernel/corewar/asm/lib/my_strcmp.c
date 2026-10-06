/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_strcmp.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb++;
    return nb;
}

int my_strcmp(char const *s1, char const *s2)
{
    int comp = 0;
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i]) {
            comp++;
        }
    }
    if (comp == my_strlen(s1)) {
        return 1;
    }
    return 0;
}
