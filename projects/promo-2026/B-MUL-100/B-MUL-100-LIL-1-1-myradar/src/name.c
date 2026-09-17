/*
** EPITECH PROJECT, 2021
** name.c
** File description:
** getting names for planes
*/

#include <stdlib.h>
#include "../includes/include.h"
#include "../includes/my.h"

int sub_get_plate(char *plate, int n)
{
    for (int i = 0; i < n; i++)
        if (plate[i] == plate[n])
            return 1;
    return 0;
}

char *get_plate(char *plate)
{
    for (int i = 0; i < 4; i++)
        plate[i] = rand() % 26 + 65;
    plate[4] = 0;
    return plate;
}

int get_P_name(int len, Plane planes[len])
{
    char *line = 0;
    size_t l = 0;
    FILE *fp = fopen("assets/planes", "r");
    char names[1000][40];
    int i = 0;

    if (test_null(fp))
        return 0;
    while ((getline(&line, &l, fp)) != -1) {
        line[my_strlen(line) - 1] = 0;
        my_strcpy(names[i], line);
        i++;
    }
    for (int j = 0; j < len; j++) {
        my_strcpy(planes[j].name, names[rand() % i]);
        get_plate(planes[j].plate);
    }
    free(line);
    return 1;
}

int get_T_plate(int len, Tower towers[len])
{
    for (int i = 0; i < len; i++)
        get_plate(towers[i].plate);
    return 1;
}
