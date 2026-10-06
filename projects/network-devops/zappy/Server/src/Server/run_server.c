/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** run_server
*/

#include "../../include/Server/server.h"
#include "../../include/Command/client_command.h"
#include "../../include/Command/gui_command.h"
#include "../../include/Server/init.h"

// init the fd_set
void init_fd_set(server_t *server)
{
    int sd;

    FD_ZERO(&server->readfds);
    FD_SET(server->server_fd, &server->readfds);
    server->max_sd = server->server_fd;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = server->clients[i].socket;
        if (sd > 0)
            FD_SET(sd, &server->readfds);
        if (sd > server->max_sd)
            server->max_sd = sd;
    }
}

// close connections and free the server
static void close_connections_and_free(server_t *server)
{
    close(server->server_fd);
    free(server->clients);
}

// close server when ctrl+c
static void handle_sigint(int sig)
{
    if (sig == SIGINT) {
        printf("\033[1;33m  Closing server\n\033[0m");
        exit(0);
    }
}

// kill a player if he has no food
void kill_player_if_no_food(server_t *server)
{
    if (server->start_game == false)
        return;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_connected &&
        server->clients[i].inventory->food == 0 &&
        server->clients[i].is_gui == false) {
            printf("Client %d is dead\n", server->clients[i].id);
            cmd_pdi(server, server->clients[i].id);
            send(server->clients[i].socket, "dead\n", 5, 0);
            disconnect_client(server, i, server->clients[i].socket);
        }
    }
}

// remove player food after 126 cycles
void update_food_of_client(server_t *server, int *cmpt_food)
{
    if (server->start_game == false)
        return;
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (server->clients[i].is_connected &&
        server->clients[i].inventory->food > 0 &&
        *cmpt_food == 126 && server->clients[i].is_gui == false) {
            server->clients[i].inventory->food -= 1;
            *cmpt_food = 0;
        }
    if (*cmpt_food == 127)
        *cmpt_food = 0;
    *cmpt_food += 1;
}

// timer for the frequence of the server
static void timer(server_t *server, struct timeval *tv)
{
    int activity;

    tv->tv_sec = 0;
    tv->tv_usec = 1000000 / server->serverConfig->frequence;
    activity = select(server->max_sd + 1,
    &server->readfds, NULL, NULL, tv);
    if ((activity < 0) && (errno != EINTR))
        perror("select error");
}

// search the team who win the game
static void search_team_win(server_t *server)
{
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (server->serverConfig->teams[i].client_nbr > 0) {
            printf("Team %s win the game\n",
            server->serverConfig->teams[i].name);
            cmd_seg(server, server->serverConfig->teams[i].name);
            close_connections_and_free(server);
            exit(0);
        }
}

// search the max level client in a team
static int search_max_level(int j, server_t *server)
{
    int nb_client = 0;
    int nb_max_lvl = 0;

    if (server->serverConfig->teams[j].client_nbr >= 6)
        nb_client = 1;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_connected == false ||
        server->clients[i].is_gui == true)
            continue;
        if (strcmp(server->clients[i].team_name,
        server->serverConfig->teams[j].name) == 0 &&
        server->clients[i].level == 8)
            nb_max_lvl++;
    }
    if (nb_client == 1 && nb_max_lvl >= 6)
        return 1;
    return 0;
}

// condition of win
void condition_of_win(server_t *server, int *cmpt_update)
{
    int teams_with_client = 0;
    int final = 0;

    *cmpt_update += 1;
    if (server->start_game == false)
        return;
    for (int i = 0; i < server->serverConfig->teams_nb; i++) {
        if (server->serverConfig->teams[i].client_nbr > 0)
            teams_with_client++;
        final = search_max_level(i, server);
        if (final == 1) {
            printf("Team %s win the game\n",
            server->serverConfig->teams[i].name);
            cmd_seg(server, server->serverConfig->teams[i].name);
            close_connections_and_free(server);
            exit(0);
        }
    }
    if (teams_with_client == 1)
        search_team_win(server);
}

// Run the server, principal function
void run_server(server_t *server)
{
    struct timeval tv;
    int cmpt_food = 0;
    int cmpt_update = 0;

    if (signal(SIGINT, handle_sigint) == SIG_ERR)
        perror("signal");
    while (1) {
        init_fd_set(server);
        timer(server, &tv);
        if (FD_ISSET(server->server_fd, &server->readfds))
        accept_new_connection(server);
        handle_client_activity(server);
        exec_stocked_command(server);
        cmd_bct(server);
        update_food_of_client(server, &cmpt_food);
        kill_player_if_no_food(server);
        update_ressource_on_map(server, &cmpt_update);
        condition_of_win(server, &cmpt_update);
    }
    close_connections_and_free(server);
}
