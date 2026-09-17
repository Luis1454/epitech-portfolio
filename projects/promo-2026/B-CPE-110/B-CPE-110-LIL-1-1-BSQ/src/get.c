/*
** EPITECH PROJECT, 2021
** get.c
** File description:
** get functions
*/

int get_position( char **map, int **mask, int nb_lines, int len_lines)
{
    int res = 0;
    int x_pos = 0;
    int y_pos = 0;

    for (int i = 0; i < nb_lines + 1; i++)
        for (int j = 0; j < len_lines; j++) {
            y_pos = mask[i][j] > res ? j : y_pos;
            x_pos = mask[i][j] > res ? i : x_pos;
            res = mask[i][j] > res ? mask[i][j] : res;
        }

    for (int i = x_pos; i > x_pos - res; i--)
        for (int j = y_pos; j > y_pos - res; j--)
            map[i - 1][j - 1] = 'x';
}

int get_min(int *lst)
{
    int res = lst[0];

    for (int i = 0; i < 3; i++)
        if (lst[i] < res)
            res = lst[i];
    return res;
}

int **get_mask(char **map, int **mask, int nb_lines, int len_lines)
{
    int lst[3];

    for (int i = 0; i < nb_lines; i++)
        for (int j = 0; j < len_lines; j++) {
            lst[0] = mask[i][j];
            lst[1] = mask[i][j + 1];
            lst[2] = mask[i + 1][j];
            mask[i + 1][j + 1] = map[i][j] == 'o' ? 0 : get_min(lst) + 1;
        }
    return mask;
}
