/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_strncmp.c
*/

#include <stddef.h>

int my_strlen(char const *str);
void my_printf(char *str, ...);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int comp = 0;
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }
    for (int i = 0; s1[i] != '\0' && i < n; i++) {
        if (s1[i] == s2[i]) {
            comp++;
        }
    }
    if (comp == my_strlen(s2)) {
        return 1;
    }
    return 0;
}
