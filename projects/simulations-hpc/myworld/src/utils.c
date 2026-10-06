/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils functions
*/

#include "../includes/my_world.h"
#include "../includes/my.h"

double get_pythagore(sfVector2f A, sfVector2f B)
{
    int a = A.x - B.x;
    int b = A.y - B.y;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    return pow(pow(a, 2) + pow(b, 2), 0.5);
}

int is_in_circle(int size, sfVector2f A, sfVector2f B)
{
    return get_pythagore(A, B) < size;
}

int is_min_lst(double *lst, int len, double nb)
{
    for (int i = 0; i < len; i++)
        if (lst[i] < nb)
            return 0;
    return 1;
}

void reset_axis(Map *map, sfVector3f *vect)
{
    vect->x /= map->camera->zoom;
    vect->y /= map->camera->zoom;
    vect->z /= map->camera->zoom;
}
