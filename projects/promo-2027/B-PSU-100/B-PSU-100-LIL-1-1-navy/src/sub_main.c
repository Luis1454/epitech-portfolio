/*
** EPITECH PROJECT, 2023
** sub_main.c
** File description:
** sub_main functions
*/

#include <signal.h>
#include "../include/my.h"
#include "../include/navy.h"

static int pid[] = {-1, -1};

int player_one(int state, char *line, char **map, struct sigaction act)
{
    int size = 2;

    pid[0] = getpid();
    my_printf("My PID is: %d\n", pid[0]);
    my_printf("Waiting for enemy connection...\n");
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    pause();
    return sub_one(size, state, line, map, act);
}

int sub_two(int size, int state, char *line, char **map, struct sigaction act)
{
    while (1) {
        if (!state) {
            my_printf("attack: ");
            getline(&line, &size, stdin);
            kill(pid[1], SIGUSR2);
            send_binary_pos(get_vect_from_str(line));
            display_map(map);
        } else {
            my_printf("waiting for enemy's attack...\n");
            sigaction(SIGUSR1, &act, NULL);
            sigaction(SIGUSR2, &act, NULL);
            pause();
        }
        state = !state;
    }
}

int player_two(int state, char *line, char **map, struct sigaction act)
{
    int size = 2;

    my_printf("My PID is: %d\n", getpid());
    my_printf("Sending connection request to PID %d\n", pid[1]);
    if (kill(pid[1], SIGUSR1) == -1) {
        my_print_error("kill\n");
        exit(1);
    }
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    return sub_two(size, state, line, map, act);
}

int main(int argc, char *argv[])
{
    struct sigaction act = (struct sigaction)
    {.sa_sigaction = signal_handler, .sa_flags = SA_SIGINFO};
    char **map = init_map();
    char *line = malloc(sizeof(char) * 2);

    map = load_map(map, argc == 2 ? argv[1] : argv[2]);
    argc == 2 ? player_one(0, line, map, act) : 0;
    if (argc == 3) {
        pid[1] = my_getnbr(argv[1]);
        player_two(0, line, map, act);
    } else {
        my_printf("Invalid number of arguments.\n");
        return 1;
    }
    return 0;
}
