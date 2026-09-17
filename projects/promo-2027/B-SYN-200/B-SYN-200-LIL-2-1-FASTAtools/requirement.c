/*
** EPITECH PROJECT, 2022
** my_strcapitalize_synthesis.c
** File description:
** capitalize a string
*/

static int my_char_isalpha(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

static int my_char_isnum(char c)
{
    return ('0' <= c && c <= '9');
}

static int my_char_isalphanum(char c)
{
    return my_char_isalpha(c) || my_char_isnum(c);
}

char *my_strcapitalize_synthesis(char *str)
{
    int state = 1;

    for (int i = 0; str[i]; i++) {
        state = state && my_char_isalphanum(str[i]) ? 0 : 1;
        if (my_char_isalpha(str[i]) && state) {
            str[i] += str[i] < 'a' ? 32 : 0;
            state = 0;
            continue;
        }
        if (my_char_isalpha(str[i]) && !state)
            str[i] += str[i] >= 'a' ? -32 : 0;
        if (my_char_isnum(str[i]))
            state = 0;
    }
    return str;
}
