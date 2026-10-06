/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_suc
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// suc command received from the gui
void command_suc(server_t *server, char *buffer)
{
    (void)buffer;
    write_log_file("received unknown command from gui\n");
    cmd_suc(server);
}
