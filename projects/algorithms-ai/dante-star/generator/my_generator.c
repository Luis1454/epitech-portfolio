/*
** EPITECH PROJECT, 2022
** my_generator.c
** File description:
** generate a maze
*/

#include "../includes/myprint.h"
#include "../includes/dante.h"

void init_maze(data_t *m)
{
    int j;

    m->map = malloc(sizeof(char *) * (m->y + 1));
    for (int i = 0; i < m->y; i++) {
        m->map[i] = malloc(sizeof(char) * (m->x + 1));
        for (j = 0; j < (m->x); j++)
            m->map[i][j] = m->mask[i][j] < 0 ? 'X' : '*';
        m->map[i][j] = 0;
    }
}


void init_mask(data_t *m)
{
    m->check = malloc(sizeof(int *) * (m->y + 1));
    m->mask = malloc(sizeof(int *) * (m->y + 1));
    for (int i = 0; i < m->y; i++) {
        m->mask[i] = malloc(sizeof(int) * m->x);
        m->check[i] = malloc(sizeof(int) * m->x);
        for (int j = 0; j < m->x; j++) {
            m->mask[i][j] = -(!(i % 2 && j % 2) || !i || !j
            || i == m->y - 1 || j == m->x - 1);
            m->mask[i][j] = !m->mask[i][j] ? rand() % 10 : -1;   
            m->mask[i][j] = (i == m->y - 2 || j == m->x - 2) && i && j
            && i < m->y - 2 && j < m->x - 2 ? rand() % 10 : m->mask[i][j]; 
        }
    }
}

void sub_core(data_t *m, int A, int B)
{
    if (m->mask[B - 1][A] != m->mask[B + 1][A])
        m->mask[B][A] = m->mask[B - 1][A];
    else if (m->mask[B][A - 1] != m->mask[B][A + 1])
        m->mask[B][A] = m->mask[B][A - 1];
    m->check[B][A] = 1;
}

int core(data_t *m)
{
    int A = 0;
    int B = 0;

    init_mask(m);
    for (int i = 0; i < m->x * m->y * 5; i++) {
        A = rand() % (m->x - 2) + 1;
        B = rand() % (m->y - 2) + 1;
        if (m->mask[B][A] == -1 && !m->check[B][A])
            sub_core(m, A, B);
    }
    init_maze(m);
    for (int i = 0; i < (m->y); i++) {
        for (int j = 0; j < m->x; j++)
            my_putchar(m->map[i][j]);
        my_putchar('\n');
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 4) {
        my_putstr("err arg\n");
        return 84;
    }
    data_t *m = malloc(sizeof(data_t));
    m->x = nbr(av[1]);
    m->y = nbr(av[2]);
    if (ac > 2)
        m->perfect = av[3];
    core(m);
    for (int i = 0; i < (m->y); i++) {
        free(m->map[i]);
    }
    free(m->map);
}
