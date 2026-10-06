/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest , char const *src , int n)
{
    int count = 0;

    for (int i = 0; src[i] != '\0'; i++)
        count++;
    if (count >= n) {
        for (int i = 0; i < n; i++)
            dest[i] = src[i];
    }
    if (count < n) {
        for (int i = 0; i < count; i++)
            dest[i] = src[i];
        dest[count] = '\0';
    }
    return dest;
}
