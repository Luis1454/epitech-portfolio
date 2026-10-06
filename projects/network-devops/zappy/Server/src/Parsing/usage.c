/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** usage
*/

#include "../../include/Parsing/parsing.h"

// the print functions are used to print the server information at
// the start of the server
void print_world_info(serverConfig_t *serverConfig)
{
    printf("==== Server Information: ====\n");
    printf("    Server IP: %s\n", serverConfig->ip);
    printf("    Port Number: %d\n", serverConfig->port_nb);
    printf("    Map Width: %d\n", serverConfig->map_width);
    printf("    Map Height: %d\n", serverConfig->map_height);
    printf("    Number of Clients: %d\n", serverConfig->client_nb);
    printf("    Frequency: %d\n", serverConfig->frequence);
    for (int i = 0; i < serverConfig->teams_nb; i++)
        printf("    Team %d: %s\n", i + 1, serverConfig->teams[i].name);
    printf("==============================\n");
    printf("Need 1 client per team to start the game\n");
}

// print the usage of the server
int print_usage(void)
{
    printf("USAGE: zappy_server -p port -x width -y height -n name1 name2");
    printf(" ... -c clientsNb -f freq\n");
    printf("option description\n");
    printf("-p port             : port number\n");
    printf("-x width            : width of the world\n");
    printf("-y height           : height of the world\n");
    printf("-n name1 name2 ...  : name of the team\n");
    printf("-c clientsNb        : number of authorized clients per team\n");
    printf("-f freq             : reciprocal of time unit for execution");
    printf(" of actions\n");
    return 1;
}
