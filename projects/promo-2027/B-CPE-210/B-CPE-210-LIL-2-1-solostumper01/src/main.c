/*
** EPITECH PROJECT, 2023
** mainc.c
** File description:
** main file
*/

#include <unistd.h>

int contain(char , const char *str);

int only_contain(const char *str, const char *chars)
{
    for (int i = 0; str[i]; i++)
        if (!contain(str[i], chars))
            return 0;
    return 1;        
}

int contain(char c, const char *str)
{
    for (int i= 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

void skip_chars(char *chars, char *str, int *i)
{
    int state = 0;
    char c[] = " ";

    for (; str[*i] && contain(str[*i], chars); (*i)++);
    if (state && !only_contain(&str[*i], chars))
        write(1, c, 1);
}

void display_message(char *str)
{
    for (int i = 0; str[i]; i++)
        contain(str[i], " \t") ? skip_chars("\t ", str, &i) : write(1, &str[i], 1);
}

int main(int argc, char * const *argv)
{
    char c[] = "\n";
    int i = 0;
    int len = 0;

    for (; argv[1][len]; len++);
    if (argc > 2)
        return 84;
    if (argc == 1 || !len) {
        write(1, c, 1);
        return 0;
    }
    display_message(argv[1]);
    write(1, c, 1);
    return 0;
}
