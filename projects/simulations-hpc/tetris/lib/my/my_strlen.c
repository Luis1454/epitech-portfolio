/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int count;

    count = 0;
    while (str[count] != 0)
        count++;
    return count;
}
