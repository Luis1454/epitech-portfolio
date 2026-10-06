/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** eject_second
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Utils/utils.h"
#include "../../../include/Command/gui_command.h"

int est_direction_fork(int other_or)
{
    if (other_or == 1)
        return 5;
    if (other_or == 2)
        return 7;
    if (other_or == 3)
        return 1;
    if (other_or == 4)
        return 3;
    return 0;
}

int sud_direction_fork(int other_or)
{
    if (other_or == 1)
        return 3;
    if (other_or == 2)
        return 5;
    if (other_or == 3)
        return 7;
    if (other_or == 4)
        return 1;
    return 0;
}

int ouest_direction_fork(int other_or)
{
    if (other_or == 1)
        return 1;
    if (other_or == 2)
        return 3;
    if (other_or == 3)
        return 5;
    if (other_or == 4)
        return 7;
    return 0;
}

int nord_direction_fork(int other_or)
{
    if (other_or == 1)
        return 7;
    if (other_or == 2)
        return 1;
    if (other_or == 3)
        return 3;
    if (other_or == 4)
        return 5;
    return 0;
}

int find_orientation(int client_or, int other_or)
{
    if (client_or == 1)
        return est_direction_fork(other_or);
    if (client_or == 2)
        return sud_direction_fork(other_or);
    if (client_or == 3)
        return ouest_direction_fork(other_or);
    if (client_or == 4)
        return nord_direction_fork(other_or);
    return 0;
}
