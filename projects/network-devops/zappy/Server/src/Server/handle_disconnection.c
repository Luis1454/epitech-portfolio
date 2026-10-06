/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** handle_disconnection
*/

#include "../../include/Server/server.h"
#include "../../include/Server/init.h"
#include "../../include/Command/gui_command.h"
#include "../../include/Utils/utils.h"

// clear all the values of the client who is not gui
static void not_gui(server_t *server, int client_disc)
{
    if (server->clients[client_disc].is_gui == false) {
        server->nbr_clients_connected--;
        cmd_pdi(server, server->clients[client_disc].id);
        write_log_file("Client %d disconnected\n",
        server->clients[client_disc].id);
        if (server->serverConfig->map->tiles[server->clients[client_disc].x]
        [server->clients[client_disc].y].player > 0) {
            server->serverConfig->map->tiles[server->clients[client_disc].x]
            [server->clients[client_disc].y].player--;
        }
    }
}

// disconnect the client
void disconnect_client(server_t *server, int client_disc, int client_socket)
{
    not_gui(server, client_disc);
    init_all_value(server, client_disc);
    if (server->clients[client_disc].team_name == NULL) {
        close(client_socket);
        return;
    }
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name,
        server->clients[client_disc].team_name) == 0) {
            server->serverConfig->teams[i].client_nbr--;
            server->serverConfig->teams[i].number_place_available++;
            break;
        }
    close(client_socket);
}

// handle the disconnection of the client
void handle_disconnection(server_t *server, int client_socket)
{
    write_log_file("Client %d disconnected\n", client_socket);
    for (int client_disc = 0; client_disc < MAX_CLIENTS; client_disc++)
        if (server->clients[client_disc].socket == client_socket) {
            disconnect_client(server, client_disc, client_socket);
            break;
        }
}
