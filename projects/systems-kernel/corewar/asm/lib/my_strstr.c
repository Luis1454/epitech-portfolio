/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_strstr1.c
*/

int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    if (my_strlen(str) < my_strlen(to_find)) {
        return 0;
    }
    if (my_strncmp(str, to_find, my_strlen(to_find)) == 0) {
        return (str);
    }
    return my_strstr((str + 1), to_find);
}
