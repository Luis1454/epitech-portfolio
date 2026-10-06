/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** set a given char for n chars in the memory
*/

void my_memset(char *str, char c, int n)
{
    for (int i = 0; i < n; i++)
        str[i] = c;
}
