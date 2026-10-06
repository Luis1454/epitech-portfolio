/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** capitalize a string
*/

int my_char_isalpha(char c)
{
    return ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z');
}

int my_char_isnum(char c)
{
    return ('0' <= c && c <= '9') || c == '.';
}

char *my_strcapitalize(char *str)
{
    int j = 0;

    for (int i = 0; str[i]; i++) {
        for (j = 0; str[i + j] && my_char_isalpha(str[i + j]); j++)
            str[i + j] += j ? (str[i + j] < 'a' ? 32 : 0) : (str[i + j] < 'a'
            ? (i && my_char_isnum(str[i + j - 1]) ? 32 : 0) : -32);
        i += j;
    }
    return str;
}
