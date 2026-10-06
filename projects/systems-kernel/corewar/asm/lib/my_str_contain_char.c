/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_str_contain_char.c
*/

int my_str_contain_char(char *str, char *c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
