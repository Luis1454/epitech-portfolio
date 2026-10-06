/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** str to int
*/

int my_putstr(char const *str);

int my_strlen(char *str);

static char get_lower(char c)
{
    return c - ('A' <= c && c <= 'Z') * 32;
}

static int is_alpha(char c)
{
    return 'a' <= get_lower(c) && get_lower(c) <= 'z';
}

static int is_nbr(char c)
{
    return '0' <= c && c <= '9';
}

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;
    int sign = 1;
    long long out = 0;

    for (; !is_nbr(str[i]); i++)
        sign *= (str[i] == '-' ? -1 : 1);
    if (i >= my_strlen(str))
        return 0;
    for (; is_nbr(str[i]); i++, n++, out *= 10) {
        out += str[i] - '0';
    }
    out /= 10;
    if ((sign > 0 && out > __INT_MAX__)
    || (out > ((long long) __INT_MAX__ + 1) && sign < 1)
    || n - (i < 0) > 10)
        return 0;
    return (int) (out * sign);
}

int my_getnbr_at(unsigned char *str, int i)
{
    int n = 0;
    int sign = 1;
    long long out = 0;

    if (i >= my_strlen(str))
        return 0;
    for (; !is_nbr(str[i]); i++)
        sign *= (str[i] == '-' ? -1 : 1);
    if (i >= my_strlen(str))
        return 0;
    for (; is_nbr(str[i]); i++, n++, out *= 10) {
        out += str[i] - '0';
    }
    out /= 10;
    if ((sign > 0 && out > __INT_MAX__)
    || (out > ((long long) __INT_MAX__ + 1) && sign < 1)
    || n - (i < 0) > 10)
        return 0;
    return (int) (out * sign);
}
