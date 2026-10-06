/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** command_sgt
*/

#include "../../../include/Server/server.h"
#include "../../../include/Command/gui_command.h"
#include "../../../include/Utils/utils.h"

// sgt command received from the gui
void command_sgt(server_t *server, char *buffer)
{
    (void)buffer;
    write_log_file("received sgt from gui\n");
    cmd_sgt(server);
}
