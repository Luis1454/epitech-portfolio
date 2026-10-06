/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** new_connection
*/

#include "../../include/Server/server.h"
#include "../../include/Utils/utils.h"

// Send WELCOME message to the new client
static void send_welcome(int sd)
{
    if (send(sd, "WELCOME\n", strlen("WELCOME\n"), 0) < 0) {
        perror("send error");
        close(sd);
    }
}

// Set the new connection
void set_new_connection(server_t *server, int new_socket)
{
    write_log_file("New connexion, socket fd: %d, ip: %s, port: %d\n",
    new_socket, inet_ntoa(server->address.sin_addr),
    ntohs(server->address.sin_port));
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (server->clients[i].socket == -1 && server->nbr_clients_connected
            <= server->serverConfig->max_clients_nbr) {
            server->clients[i].socket = new_socket;
            server->clients[i].id = i;
            send_welcome(new_socket);
            break;
        }
}

// Accept new connection from client
void accept_new_connection(server_t *server)
{
    int new_socket;

    new_socket = accept(server->server_fd,
    (struct sockaddr *)&server->address,
    (socklen_t *)&server->addrlen);
    if (new_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    set_new_connection(server, new_socket);
}
