/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** handle_client
*/

#include "../../include/Server/server.h"
#include "../../include/Server/init.h"
#include "../../include/Command/gui_command.h"
#include "../../include/Command/client_command.h"
#include "../../include/Utils/utils.h"

// verify if the team is full
static int verif_teams_full(server_t *server, char *buffer, int j)
{
    if (strcmp(server->serverConfig->teams[j].name, buffer) == 0) {
        if (server->serverConfig->teams[j].number_place_available < 1) {
            write_log_file("Team %s is full\n", buffer);
            return 1;
        }
        server->serverConfig->teams[j].client_nbr++;
        server->serverConfig->teams[j].number_place_available--;
    }
    return 0;
}

// update the number of clients in the team
static int update_teams(server_t *server, char *buffer)
{
    for (int j = 0; j < server->serverConfig->teams_nb; j++)
        if (verif_teams_full(server, buffer, j) == 1)
            return 1;
    return 0;
}

// add the client in the team and send the first connection message
static int add_in_client(server_t *server, char *buffer, int client, int i)
{
    if (strcmp(server->serverConfig->teams[i].name, buffer) == 0) {
        if (update_teams(server, buffer) == 1) {
            return 2;
        }
        write_log_file("Client is a player\n");
        set_value_for_client(server, client, buffer);
        send_first_connection_client(server, client);
        send_pnw_client(server, client);
        server->nbr_clients_connected++;
        return 1;
    }
    return 0;
}

// disconnect the client if he is not authenticated
static void client_not_authenticated(server_t *server, int client)
{
    close(server->clients[client].socket);
    init_all_value(server, client);
}

// dispatch the client in the right team
void add_in_teams(server_t *server, char *buffer, int client)
{
    for (int i = 0; i < server->serverConfig->teams_nb; i++) {
        if (strcmp(buffer, "GRAPHIC") == 0) {
            server->clients[client].is_gui = true;
            send_first_connection_gui(server);
            server->clients[client].team_name = strdup(buffer);
            return;
        }
        if (add_in_client(server, buffer, client, i) == 1)
            return;
    }
    client_not_authenticated(server, client);
}

// handle the client
int handle_client(int client_socket, int client, server_t *server)
{
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    int bytes_read;

    buffer[0] = '\0';
    bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read <= 0)
        handle_disconnection(server, client_socket);
    if (bytes_read > 0) {
        buffer[bytes_read - 1] = '\0';
        write_log_file("Reçu du client : %s\n", buffer);
        if (server->clients[client].is_connected == false) {
            add_in_teams(server, buffer, client);
            server->clients[client].is_connected = true;
        } else
            handle_command(server, buffer, client);
    }
    return bytes_read;
}

// handle the client activity
void handle_client_activity(server_t *server)
{
    int sd;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = server->clients[i].socket;
        if (sd == -1)
            continue;
        if (FD_ISSET(sd, &server->readfds))
            handle_client(sd, i, server);
    }
}
