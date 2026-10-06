/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include "../include.h"
    #include "server_struct.h"

void run_server(server_t *server);
void handle_client_activity(server_t *server);
void accept_new_connection(server_t *server);
void stock_request(server_t *server, char *buffer, int client);
void send_pnw_gui(server_t *server, int i);
void send_pnw_client(server_t *server, int i);
void send_first_connection_gui(server_t *server);
void set_value_for_client(server_t *server, int client, char *buffer);
void send_first_connection_client(server_t *server, int client);
void handle_command(server_t *server, char *buffer, int client);
void disconnect_client(server_t *server, int client_disc, int client_socket);
void update_ressource_on_map(server_t *server, int *cmpt_update);
void handle_disconnection(server_t *server, int client_socket);

#endif /* !SERVER_H_ */
