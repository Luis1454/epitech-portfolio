/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib test
*/

int my_strlen(char const *str)
{
    int cnt = 0;

    while (str[cnt])
        cnt++;

    return cnt;
}
