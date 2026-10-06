/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday06-mathis.zucchero
** File description:
** my_recstr.c
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int swap = 0; swap < len; swap++, len--) {
        temp = str[swap];
        str[swap] = str[len];
        str[len] = temp;
    }
    return str;
}
