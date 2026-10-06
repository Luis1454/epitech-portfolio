/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** client_command
*/

#ifndef CLIENT_COMMAND_H_
    #define CLIENT_COMMAND_H_

    #include "../Server/server.h"

typedef struct look_s {
    int x;
    int y;
    int l;
    int t;
    int to_look;
    char *str;
} look_t;

void cmd_forward(client_t *client, char *cmd);
void cmd_right(client_t *client, char *cmd);
void cmd_left(client_t *client, char *cmd);
// for look
char *get_tile_content(char *str, int x, int y, server_t *server);
void look_direction(server_t *server, client_t *client, look_t *look,
    char **str);
//
void action_look(server_t *server, client_t *client, char **str, look_t *look);
void cmd_look(client_t *client, char *cmd);
void cmd_inventory(client_t *client, char *cmd);
void cmd_broadcast(client_t *client, char *cmd);
void cmd_connect_nbr(client_t *client, char *cmd);
void cmd_fork(client_t *client, char *cmd);
void cmd_eject(client_t *client, char *cmd);
// for take_object
int verif_ressource(char *cmd);
//
void cmd_take_object(client_t *client, char *cmd);
void cmd_set_object(client_t *client, char *cmd);
void cmd_incantation(client_t *client, char *cmd, server_t *server);
void cmd_unknown(client_t *client, char *cmd);

void exec_stocked_command(server_t *server);
void handle_clients_command(server_t *server, int client, char *buffer);

void send_broadcast(client_t *client, char *cmd, server_t *server);
void send_connect_nbr(client_t *client, char *cmd, server_t *server);
void send_eject(client_t *client, char *cmd, server_t *server);
void send_fork(client_t *client, char *cmd, server_t *server);
void send_forward(client_t *client, char *cmd, server_t *server);
void send_incantation(client_t *client, char *cmd, server_t *server);
void send_inventory(client_t *client, char *cmd, server_t *server);
void send_left(client_t *client, char *cmd, server_t *server);
void send_look(client_t *client, char *cmd, server_t *server);
void send_right(client_t *client, char *cmd, server_t *server);
void send_set_object(client_t *client, char *cmd, server_t *server);
void send_take_object(client_t *client, char *cmd, server_t *server);
void send_response(client_t *client, char *cmd, server_t *server);
// for broadcast
void send_message_broadcast(int direction,
    char *cmd, client_t *receiver);
int est_direction(int dx, int dy);
int sud_direction(int dx, int dy);
int ouest_direction(int dx, int dy);
int nord_direction(int dx, int dy);
//
// for look
int find_orientation(int client_or, int other_or);
//
//for incantation
bool condition_to_elevation(client_t *client, server_t *server);
//

#endif /* !CLIENT_COMMAND_H_ */
