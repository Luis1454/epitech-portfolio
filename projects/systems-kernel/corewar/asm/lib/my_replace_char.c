/*
** EPITECH PROJECT, 2022
** B-CPE-200-LIL-2-1-corewar-mathis.zucchero
** File description:
** my_replace_char.c
*/

char *replace_char(char *line, char d, char r)
{
    int i = 0;

    for (; line[i] != '\0'; i++) {
        if (line[i] == d)
            line[i] = r;
    }
    return line;
}
