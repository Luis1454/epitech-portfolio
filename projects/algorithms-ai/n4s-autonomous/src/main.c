/*
** EPITECH PROJECT, 2022
** librairie cmpt
** File description:
** main.c
*/

#include "../include/ia_project.h"
#include "../include/my.h"

int sub_game_loop(char *command, size_t len, char **tab)
{
    if (!tab || my_tablen(tab) < 36)
        return 84;
    if (tab[35])
        free(tab[35]);
    tab[35] = NULL;
    dprintf(1, "WHEELS_DIR:%f\n", get_rot(&tab[3]));
    getline(&command, &len, stdin);
    if (!go_back(tab))
        dprintf(1, "CAR_FORWARD:%f\n", get_speed(&tab[3]));
    else
        dprintf(1, "CAR_BACKWARDS:%f\n", get_speed(&tab[3]));
    getline(&command, &len, stdin);
    return 0;
}

int game_loop(char *command, size_t len)
{
    char **tab = NULL;

    while (1) {
        dprintf(1, "%s\n", "GET_INFO_LIDAR");
        getline(&command, &len, stdin);
        if (!command || !my_strcmp(command, "\n"))
            return 84;
        tab = my_str_to_word_array(command, ':');
        if (!tab || sub_game_loop(command, len, tab)) {
            tab ? free_array(tab) : 0;
            return 84;
        }
        if (my_strstr(command, "Track Cleared") || !is_lidar(tab)) {
            tab ? free_array(tab) : 0;
            return 0;
        }
        tab ? free_array(tab) : 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    char *command = NULL;
    size_t len = 0;
    if (ac != 1)
        return 84;
    av = av;
    dprintf(1, "%s\n", "START_SIMULATION");
    getline(&command, &len, stdin);
    if (!command || !my_strcmp(command, "\n")
    || game_loop(command, len))
        return 84;
    dprintf(2, "%s\n", "STOP_SIMULATION");
    return 0;
}
