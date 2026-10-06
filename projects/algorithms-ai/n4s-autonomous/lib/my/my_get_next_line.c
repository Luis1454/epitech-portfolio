/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-minishell1-alexis.salaun
** File description:
** my_get_next_line.c
*/

int get_next_line(char *str)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != '\n'; i++);
    for (; str[i] != '\0' && str[i] != '\n'; i++);
    return i + 1;
}
