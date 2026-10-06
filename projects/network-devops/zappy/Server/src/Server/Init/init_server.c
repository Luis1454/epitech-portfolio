/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** init_server
*/

#include "../../../include/Server/init.h"

// bind and listen the server
void start_bind_and_listen(server_t *server)
{
    if (bind(server->server_fd, (struct sockaddr *)&server->address,
    sizeof(server->address)) < 0) {
        perror("bind failed");
        close(server->server_fd);
        exit(EXIT_FAILURE);
    }
    if (listen(server->server_fd, 3) < 0) {
        perror("listen");
        close(server->server_fd);
        exit(EXIT_FAILURE);
    }
    server->addrlen = sizeof(server->address);
}

// init the value of the server
void init_value(server_t *server)
{
    server->update = 0;
    server->nbr_clients_connected = 0;
    server->serverConfig->max_clients_nbr = server->serverConfig->teams_nb *
    server->serverConfig->client_nb + 1;
    server->clients = malloc(sizeof(client_t) * MAX_CLIENTS);
    server->clients_nbr = MAX_CLIENTS;
    for (int i = 0; i < MAX_CLIENTS; i++)
        server->clients[i].socket = 0;
}

void init_server_two(server_t *server)
{
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->serverConfig->port_nb);
    start_bind_and_listen(server);
    for (int i = 0; i < server->serverConfig->teams_nb; i++) {
        server->serverConfig->teams[i].name =
        strdup(server->serverConfig->teams[i].name);
        server->serverConfig->teams[i].client_nbr = 0;
        server->serverConfig->teams[i].number_place_available =
        server->serverConfig->client_nb;
        server->serverConfig->teams[i].fork = 0;
        server->serverConfig->teams[i].egg = malloc(sizeof(egg_fork_t) *
        MAX_CLIENTS);
        for (int j = 0; j < MAX_CLIENTS; j++) {
            server->serverConfig->teams[i].egg[j].id = -1;
            server->serverConfig->teams[i].egg[j].is_hatched = 0;
            server->serverConfig->teams[i].egg[j].is_fork = 0;
        }
    }
}

// init the server
void init_server(server_t *server)
{
    int opt = 1;

    init_value(server);
    init_map(server);
    init_client(server);
    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR,
    &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server->server_fd);
        exit(EXIT_FAILURE);
    }
    init_server_two(server);
}
