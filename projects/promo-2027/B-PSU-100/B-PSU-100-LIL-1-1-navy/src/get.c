/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** get functions
*/

#include <signal.h>
#include "../include/my.h"
#include "../include/navy.h"

static int pid[] = {-1, -1};

vect_2i get_vect_from_str(char *str)
{
    int x = str[0] - '1';
    int y = str[1] - 'A';

    return (vect_2i){x, y};
}

int get_map(char **map, char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;

    if (file == NULL)
        return 1;
    fclose(file);
    if (line)
        free(line);
    return 0;
}

vect_2i receve_binary_pos(void)
{
    vect_2i pos = (vect_2i){0, 0};
    struct sigaction act = (struct sigaction) {signal_handler, SA_SIGINFO};

    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    for (int i = 0; i < 8; i++) {
        pause();
        if (pid[2] == SIGUSR1)
            pos.x |= (1 << i);
    }
    for (int i = 0; i < 8; i++) {
        pause();
        if (pid[2] == SIGUSR1)
            pos.y |= (1 << i);
    }
    return pos;
}

void signal_handler(int sig, siginfo_t *siginfo, void *context)
{
    int id = getpid();

    if (sig == SIGUSR1) {
        if (id == pid[0]) {
            pid[1] = siginfo->si_pid;
            my_printf("Enemy connected, PID %d\n", pid[1]);
            return;
        }
        if (id == pid[1])
            my_printf("Connection established\n");
    } else if (sig == SIGUSR2)
        my_printf("hit\n");
}
