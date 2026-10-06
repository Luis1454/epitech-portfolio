/*
** EPITECH PROJECT, 2022
** contain.c
** File description:
** contain fonctions
*/

int find_out(const char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return i;
    return -1;
}
