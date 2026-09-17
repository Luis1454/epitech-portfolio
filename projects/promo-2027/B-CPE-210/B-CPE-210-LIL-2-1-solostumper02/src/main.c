/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file
*/

#include <unistd.h>

int check_char(char a, char b)
{
    char tmp_a = a + ('A' <= a && a <= 'Z') * ('a' - 'A');
    char tmp_b = b + ('A' <= b && b <= 'Z') * ('a' - 'A');

    return tmp_a == tmp_b;
}

int main(int argc, char * const *argv)
{
    int len = 0;

    if (argc < 2) {
        write(2, "Error: missing arguments.\n", 26);
        return 84;
    }
    for (; argv[1][len]; len++);
    for (int i = 0; i < len / 2 + 1; i++)
        if (!check_char(argv[1][i], argv[1][len - i - 1])) {
            write(1, "not a palindrome.\n", 18);
            return 0;
        }
    write(1, "palindrome!\n", 12);
    return 0;
}
