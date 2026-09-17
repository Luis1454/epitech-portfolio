/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task01
*/

char *my_strcat(char *dest , char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a]){
        a++;
    }

    while (src[b]) {
        dest[a+b] = src[b];
        b++;
    }

    dest[a+b] = '\0';
    return dest;
}
