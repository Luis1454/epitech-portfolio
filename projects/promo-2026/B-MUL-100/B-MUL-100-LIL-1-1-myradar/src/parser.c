/*
** EPITECH PROJECT, 2021
** parser.c
** File description:
** .rdr files handler
*/

#include "../includes/include.h"
#include "../includes/my.h"

int skip_spaces(char *line, int i)
{
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    return i;
}

int get_T_len(int len, Tower towers[len])
{
    int i = 0;

    while (towers[i].id)
        i++;
    return i;
}

int get_objects(char *line, int len, Plane planes[len], Tower towers[len])
{
    int T;
    int P;
    char lst[10][10];
    int n = 0;
    int t = 0;
    int j;

    for (int i = 0; i < my_strlen(line); i++) {
        i = skip_spaces(line, i);
        if (line[i] == '#' || line[i] == '\n')
            return 0;
        j = 0;
        if (line[i + j] == '-') {
            lst[n][j] = line[i + j];
            j++;
        }
        while (is_alphanumeric(line[i + j]) && i + j < my_strlen(line)) {
            lst[n][j] = line[i + j];
            j++;
        }
        lst[n][j] = 0;
        n++;
        i += j;
    }

    T = get_T_len(len, towers);
    P = get_P_len(len, planes);

    lst[n][0] = 0;
    if (lst[0][0] == 'A') {
        planes[P].X = my_getnbr(lst[1]);
        planes[P].Y = my_getnbr(lst[2]);
        planes[P].Xspeed = my_getnbr(lst[3]);
        planes[P].Yspeed = my_getnbr(lst[4]);
        planes[P].id = P + 1;
    } else if (lst[0][0] == 'T') {
        towers[T].X = my_getnbr(lst[1]);
        towers[T].Y = my_getnbr(lst[2]);
        towers[T].radius = my_getnbr(lst[3]);
        towers[T].id = T + 1;
    }
    return 1;
}

int parser(char *filename, Plane planes[], Tower towers[])
{
    Stat st;
    int len = st.nbPlanes;
    char *line = NULL;
    char ext[] = "";
    char check[] = " Make sure that the file given in parameter is correct.\n";
    size_t l = 0;
    ssize_t read;
    FILE *fp = fopen(filename, "r");

    my_strscpy(ext, filename, get_len_bf_dot(filename));
    if (!are_equals(ext, ".rdr")) {
        my_putstr("./my_radar: .rdr file incorrectly formatted.");
        my_putstr(check);
        return 0;
    }
    if (fp == NULL) {
        my_putstr("./my_radar: .rdr file not found.");
        my_putstr(check);
        return 0;
    }
    while ((read = getline(&line, &l, fp)) != -1)
        get_objects(line, len, planes, towers);
    free(line);
    return 1;
}
