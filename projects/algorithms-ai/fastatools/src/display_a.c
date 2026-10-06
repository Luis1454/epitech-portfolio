/*
** EPITECH PROJECT, 2023
** display_a.c
** File description:
** display function
*/

#include "../include/my.h"
#include "../include/fasta.h"

int display_one(char **names, char **arr)
{
    for (int i = 0; arr[i]; i++) {
        arr[i] = my_strupcase(arr[i]);
        my_printf("%s%s\n", names[i], arr[i]);
    }
    free_arr(arr);
    return 0;
}

int display_two(char **names, char **arr)
{
    for (int i = 0; arr[i]; i++) {
        my_printf("%s", names[i]);
        arr[i] = my_strupcase(arr[i]);
        for (int j = 0; arr[i][j]; j++)
            my_printf("%c", arr[i][j] == 'T' ? 'U' : arr[i][j]);
        my_printf("\n");
    }
    free_arr(arr);
    return 0;
}

int display_three(char **names, char **arr)
{
    for (int i = 0; arr[i]; i++) {
        my_printf("%s", names[i]);
        arr[i] = my_strupcase(arr[i]);
        for (int j = my_strlen(arr[i]) - 1; j >= 0; j--)
            my_printf("%c", arr[i][j] == 'A' ? 'T' :
            arr[i][j] == 'T' ? 'A' :
            arr[i][j] == 'C' ? 'G' : 'C');
        my_printf("\n");
    }
    return 0;
}

int display_usage(void)
{
    my_putstr("USAGE\n\t./FASTAtools option\n\n");
    my_putstr("DESCRIPTION\n\t");
    my_putstr("option 1: read FASTA from the standard input, ");
    my_putstr("write the DNA sequences to the\n\t\tstandard output\n\t");
    my_putstr("option 2: read FASTA from the standard input, ");
    my_putstr("write the RNA sequences to the\n\t\tstandard output\n");
    my_putstr("\toption 3: read FASTA from the standard input, ");
    my_putstr("write the reverse complement\n\t\tto the standard output\n");
    my_putstr("\toption 4: read FASTA from the standard input, ");
    my_putstr("write the k-mer list to the\n\t\tstandard output\n");
    my_putstr("\toption 5: read FASTA from the standard input, ");
    my_putstr("write the coding sequences\n\t\tlist to the standard output\n");
    my_putstr("\toption 6: read FASTA from the standard input, ");
    my_putstr("write the amino acids list to\n\t\tthe standard output\n");
    my_putstr("\toption 7: read FASTA from the standard input ");
    my_putstr("containing exactly 2 sequences,\n\t\talign them and ");
    my_putstr("write the result of the standart output\n");
    my_putstr("\tk: size of the k-mers for option 4\n");
    return 0;
}
