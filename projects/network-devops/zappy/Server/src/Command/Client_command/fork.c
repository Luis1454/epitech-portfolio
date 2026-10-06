/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** fork
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// add new valid client
static int add_new_valid_client(server_t *server, char *teams)
{
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name, teams) == 0)
            server->serverConfig->teams[i].number_place_available++;
    return 0;
}

// send the egg to the gui
void send_egg_to_gui(client_t *client, server_t *server, egg_fork_t egg_fork)
{
    egg_t egg;

    egg.egg_id = egg_fork.id;
    egg.x = egg_fork.x;
    egg.y = egg_fork.y;
    egg.player_id = client->id;
    cmd_enw(server, egg);
}

// set the egg
static void set_egg(client_t *client, server_t *server, int teams)
{
    int value = 0;

    server->serverConfig->teams[teams].fork++;
    value = server->serverConfig->teams[teams].fork;
    server->serverConfig->teams[teams].egg[value].id = value;
    server->serverConfig->teams[teams].egg[value].x = client->x;
    server->serverConfig->teams[teams].egg[value].y = client->y;
    server->serverConfig->teams[teams].egg[value].is_fork = 1;
    send_egg_to_gui(client, server,
    server->serverConfig->teams[teams].egg[value]);
}

// fork action
int fork_action(client_t *client, server_t *server)
{
    int teams = 0;

    if (server->serverConfig->map->tiles[client->y][client->x].egg == true) {
        return 1;
    } else {
        server->serverConfig->map->tiles[client->y][client->x].egg = true;
        add_new_valid_client(server, client->team_name);
    }
    for (int i = 0; i < server->serverConfig->teams_nb; i++)
        if (strcmp(server->serverConfig->teams[i].name,
        client->team_name) == 0)
            teams = i;
    set_egg(client, server, teams);
    return 0;
}

// make the fork
static void make_fork(client_t *client, char *cmd, server_t *server)
{
    (void)cmd;
    if (fork_action(client, server) == 0)
        send(client->socket, "ok\n", 3, 0);
    else
        send(client->socket, "ko\n", 3, 0);
}

// send the fork
void send_fork(client_t *client, char *cmd, server_t *server)
{
    if (client->is_fork == 1) {
        make_fork(client, cmd, server);
        client->is_fork = 0;
        client->request_action = 0;
    }
}

// fork command
void cmd_fork(client_t *client, char *cmd)
{
    (void)cmd;
    client->is_fork = 1;
    client->action = 42;
}
