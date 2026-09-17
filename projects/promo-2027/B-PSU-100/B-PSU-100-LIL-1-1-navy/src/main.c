/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main functions
*/

#include <signal.h>
#include "../include/my.h"
#include "../include/navy.h"

static int pid[] = {-1, -1};

int check_attack(char *input, char **map)
{
    return my_strlen(input) == 2
    && input[0] >= '1' && input[0] <= '8'
    && input[1] >= 'A' && input[1] <= 'H';
}

void send_binary_pos(vect_2i pos)
{
    for (int i = 0; i < 8; i++) {
        if (pos.x & (1 << i))
            kill(pid[1], SIGUSR1);
        else
            kill(pid[1], SIGUSR2);
    }
    for (int i = 0; i < 8; i++) {
        if (pos.y & (1 << i))
            kill(pid[1], SIGUSR1);
        else
            kill(pid[1], SIGUSR2);
    }
}

int sub_one(int size, int state, char *line, char **map, struct sigaction act)
{
    while (1) {
        if (!state) {
            my_printf("waiting for enemy's attack...\n");
            sigaction(SIGUSR1, &act, NULL);
            sigaction(SIGUSR2, &act, NULL);
            pause();
        } else {
            my_printf("attack: ");
            getline(&line, &size, stdin);
            kill(pid[1], SIGUSR2);
            send_binary_pos(get_vect_from_str(line));
            display_map(map);
        }
        state = !state;
    }
    return 0;
}
