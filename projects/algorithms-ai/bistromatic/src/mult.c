/*
** EPITECH PROJECT, 2021
** B-CPE-101-LIL-1-1-bistromatic-maxence.canler
** File description:
** mult
*/

#include <stdlib.h>
#include "my.h"

void free_array(char **arr, int l1)
{
    for (int i = 0; i < l1; i++) {
        free(arr[i]);
    }
    free(arr);
}

void get_array(char **arr, char *nb1, int len)
{
    for (int i = 0; i < my_strlen(nb1); i++) {
        arr[i] = malloc(sizeof(char) * len);
        for (int j = 0; j < len; j++)
            arr[i][j] = 0;
    }
}

void get_mult(char **arr, char *nb1, char *nb2, int len)
{
    int offset = 0;
    int trunc;
    int f1 = 0;
    int f2 = 0;

    if (nb1[0] == '-')
        f1 = 1;

    if (nb2[0] == '-')
        f2 = 1;

    for (int i = my_strlen(nb1) - 1; i >= f1; i--) {
        for (int j = my_strlen(nb2) - 1; j >= f2; j--) {
            trunc = (nb1[my_strlen(nb1) - 1 - i] - 48) * (nb2[j] - 48);
            if (trunc > 9) {
                arr[i][j + my_strlen(nb1) - i - 1] = trunc / 10;
                trunc %= 10;
            }
            arr[i][j + my_strlen(nb1) - i] += trunc;
        }
        offset++;
    }
}

void get_out(char **arr, char *out, char *nb1, char *nb2, int len)
{
    int sum;
    int n = 0;
    int off = 0;
    int is_neg = 0;

    for (int i = len - 1; i >= 0; i--) {
        sum = 0;
        for (int j = my_strlen(nb1) - 1; j >= 0; j--) {
            if (0 < arr[j][i] && arr[j][i] <= 9)
                sum += arr[j][i];
        }
        arr[0][i] += sum;
        arr[0][i] = sum % 10;
        arr[0][i - 1] += sum / 10;
        out[i] = '0' + arr[0][i];
    }

    while (out[n] == '0') {
        out[n] = 0;
        n++;
    }

    while (out[off] == 0)
        off++;

    if (nb1[0] != nb2[0] && (nb1[0] == '-' || nb2[0] == '-')) {
        out[0] = '-';
        is_neg = 1;
    }

    for (int i = 0; i < len + 2; i++)
        out[i + is_neg] = out[i + off];

}

char *mult(char *nb1, char *nb2)
{
    if (nb1 != NULL && nb2 != NULL){
        int len = my_strlen(nb1) + my_strlen(nb2);
        char **arr = malloc(sizeof(char *) * my_strlen(nb1));
        char *out = malloc(sizeof(char) * (len + 2));
        int n = len;

        get_array(arr, nb1, len);

        get_mult(arr, nb1, nb2, len);

        get_out(arr, out, nb1, nb2, len);

        free_array(arr, my_strlen(nb1));

        return out;
    }
    return "0";
}