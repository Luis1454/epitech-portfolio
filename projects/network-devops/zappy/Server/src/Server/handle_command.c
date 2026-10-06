/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** handle_command
*/

#include "../../include/Server/server.h"
#include "../../include/Command/gui_command.h"
#include "../../include/Command/client_command.h"
#include "../../include/Utils/utils.h"

// process the command sent by the gui
void process_command(server_t *server, char *buffer, int client)
{
    if (strncmp(buffer, "msz", 3) == 0)
        return command_msz(server, buffer);
    if (strncmp(buffer, "bct", 3) == 0)
        return command_bct(server, buffer, client);
    if (strncmp(buffer, "mct", 3) == 0)
        return command_mct(server, buffer);
    if (strncmp(buffer, "tna", 3) == 0)
        return command_tna(server, buffer);
    if (strncmp(buffer, "ppo", 3) == 0)
        return command_ppo(server, buffer);
    if (strncmp(buffer, "plv", 3) == 0)
        return command_plv(server, buffer);
    if (strncmp(buffer, "pin", 3) == 0)
        return command_pin(server, buffer);
    if (strncmp(buffer, "sgt", 3) == 0)
        return command_sgt(server, buffer);
    if (strncmp(buffer, "sst", 3) == 0)
        return command_sst(server, buffer);
    command_suc(server, buffer);
}

// handle the command sent by the gui
void handle_gui_command(server_t *server, char *buffer, int client)
{
    char **array;

    array = str_to_word_array(buffer, "\n");
    if (array == NULL)
        exit(84);
    cmd_msz(server);
    cmd_sgt(server);
    cmd_bct(server);
    cmd_tna(server);
    for (int i = 0; array[i] != NULL; i++)
        process_command(server, array[i], client);
}

// handle the command sent by the client
void handle_command(server_t *server, char *buffer, int client)
{
    if (server->clients[client].is_gui == true)
        handle_gui_command(server, buffer, client);
    else
        stock_request(server, buffer, client);
}
