/*
** EPITECH PROJECT, 2022
** task 02
** File description:
** C pool day 08
*/

#include <stdlib.h>

#include "../../include/my.h"

char *concat_params(int argc, char **argv)
{
    char *ptm;
    int len = 0;
    int i = 0;

    for (; i < argc ; i++ ) {
        len = len + my_strlen(argv[i]) + 1;
    }
    ptm = malloc(sizeof(char) * (len + 1));
    ptm[0] = '\0';
    for (i = 0; i < argc; i++) {
        my_strcat(ptm, argv[i]);
        if (i < argc - 1)
            my_strcat(ptm, "\n");
    }
    my_strcat(ptm, "\0");
    return ptm;
}
