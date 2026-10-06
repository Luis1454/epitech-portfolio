/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_strnpy.c
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; i++) {
        if (dest[i] == '\0') {
            src = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    if (n > my_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}
