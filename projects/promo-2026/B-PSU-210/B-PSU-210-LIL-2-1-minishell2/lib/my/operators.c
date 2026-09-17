/*
** EPITECH PROJECT, 2021
** operators.c
** File description:
** arithmetic tools
*/

int min(int A, int B)
{
    if (A < B)
        return A;
    return B;
}

int max(int A, int B)
{
    if (A > B)
        return A;
    return B;
}

int pwr(int num, int pwr)
{
    int out = num;

    for (int i = 1; i < pwr; i++)
        out *= num;
    return out;
}

int root(int num)
{
    return pwr(num, 0.5);
}
