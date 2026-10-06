/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_isnum.c
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int is_alpha = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            is_alpha += 1;
        }
    }
    if (is_alpha == my_strlen(str) || my_strlen == 0) {
        return 1;
    } else {
        return 0;
    }
}
