/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** look
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Utils/utils.h"

// init the struct
static void init_struct(look_t *look, int x, int y)
{
    look->x = x;
    look->y = y;
    look->l = 1;
    look->t = 0;
    look->to_look = 3;
}

// make the look
static void make_look(client_t *client, char *cmd, server_t *server)
{
    int x = client->x;
    int y = client->y;
    look_t look;
    char *str = malloc(sizeof(char) * BUFFER_SIZE);

    (void)cmd;
    str[0] = '\0';
    str = add_in_str(str, "[");
    str = get_tile_content(str, x, y, server);
    str = add_in_str(str, ",");
    init_struct(&look, x, y);
    action_look(server, client, &str, &look);
    str[strlen(str)] = '\0';
    str = add_in_str(str, " ]\n");
    send(client->socket, str, strlen(str), 0);
}

// send the look
void send_look(client_t *client, char *cmd, server_t *server)
{
    if (client->is_look == 1) {
        make_look(client, cmd, server);
        client->is_look = 0;
        client->request_action = 0;
    }
}

// look command
void cmd_look(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_look = 1;
    client->action = 7;
}
