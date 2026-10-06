/*
** EPITECH PROJECT, 2023
** my_str_is_number
** File description:
** dsk
*/

int my_str_is_numb(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('0' <= str[i] && str[i] <= '9'))
            return 0;
    }
    return 1;
}
