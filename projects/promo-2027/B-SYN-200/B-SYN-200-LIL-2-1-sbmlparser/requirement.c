/*
** EPITECH PROJECT, 2023
** requirement.c
** File description:
** SBML parser file
*/

static int my_char_is_alphanum(char c)
{
    return (c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9');
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
}

static void skip_non_alphanum(char const *str, int *i)
{
    for (; !(my_char_is_alphanum(str[*i])) && str[*i]; (*i)++);
}

static char **sub_word_array(char **out, char const *str, char *tmp, int n)
{
    int len = 0;
    int i = 0;
    for (; str[len]; len++);
    for (; !(my_char_is_alphanum(str[i])) && str[i]; i++);
    for (int nb = 0; i <= len; i++) {
        if (!(my_char_is_alphanum(str[i]))) {
            skip_non_alphanum(str, &i);
            out[nb] = malloc(sizeof(char) * (n + 1));
            my_strcpy(out[nb], tmp);
            n = 0;
            out[++nb] = 0;
        }
        tmp[n++] = str[i];
        tmp[n] = 0;
    }
    return out;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **out;
    char *tmp;
    int nb = 1;
    int len = 0;

    for (; str[len]; len++);
    if (!len) {
        out = malloc(sizeof(char *) * 1);
        out[0] = 0;
        return out;
    }
    for (int i = 0; i < len; i++)
        if (!my_char_is_alphanum(str[i]) && ++nb)
            skip_non_alphanum(str, &i);
    tmp = malloc(sizeof(char) * len + 1);
    out = malloc(sizeof(char *) * (nb + 1));
    out = sub_word_array(out, str, tmp, 0);
    out[nb] = 0;
    return out;
}
