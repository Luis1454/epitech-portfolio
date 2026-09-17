/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task05
*/

int min(int A, int B);

int max(int A, int B);

double sqrt(double nb)
{
    double low = min(1, nb);
    double high = max(1, nb);
    double out;

    while (100 * high * high > nb)
        high *= 0.1;
    while (100 * low * low < nb)
        low *= 10;
    for (int i = 0; i < 100; i++) {
        out = (low + high) / 2;
        if (out * out == nb)
            return out;
        if (out * out > nb)
            high = out;
        else
            low = out;
    }
    return out;
}
