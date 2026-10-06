/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** update_ressource
*/

#include "../../include/Server/server.h"

// compt the ressource on the map
static density_t add_in_density(density_t density, server_t *server)
{
    for (int i = 0; i < server->serverConfig->map_height; i++)
        for (int j = 0; j < server->serverConfig->map_width; j++) {
            density.food +=
            server->serverConfig->map->tiles[i][j].food;
            density.linemate +=
            server->serverConfig->map->tiles[i][j].linemate;
            density.deraumere +=
            server->serverConfig->map->tiles[i][j].deraumere;
            density.sibur +=
            server->serverConfig->map->tiles[i][j].sibur;
            density.mendiane +=
            server->serverConfig->map->tiles[i][j].mendiane;
            density.phiras +=
            server->serverConfig->map->tiles[i][j].phiras;
            density.thystame +=
            server->serverConfig->map->tiles[i][j].thystame;
        }
    return density;
}

// get the density of the ressource on the map
static density_t calcul_density(density_t density, server_t *server)
{
    int div;

    div = (server->serverConfig->map_height * server->serverConfig->map_width);
    density = add_in_density(density, server);
    density.food = density.food / div;
    density.linemate = density.linemate / div;
    density.deraumere = density.deraumere / div;
    density.sibur = density.sibur / div;
    density.mendiane = density.mendiane / div;
    density.phiras = density.phiras / div;
    density.thystame = density.thystame / div;
    return density;
}

// init the density struct
density_t get_density(server_t *server)
{
    density_t density;

    density.food = 0;
    density.linemate = 0;
    density.deraumere = 0;
    density.sibur = 0;
    density.mendiane = 0;
    density.phiras = 0;
    density.thystame = 0;
    density = calcul_density(density, server);
    return density;
}

// update the ressource on the map if the density is too low part 4
static void update_ressource_on_map4(server_t *server, density_t density)
{
    int x;
    int y;

    while (density.phiras < 0.08) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].phiras += 1;
        density = get_density(server);
    }
    while (density.thystame < 0.05) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].thystame += 1;
        density = get_density(server);
    }
}

// update the ressource on the map if the density is too low part 3
static void update_ressource_on_map3(server_t *server, density_t density)
{
    int x;
    int y;

    while (density.sibur < 0.1) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].sibur += 1;
        density = get_density(server);
    }
    while (density.mendiane < 0.1) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].mendiane += 1;
        density = get_density(server);
    }
    update_ressource_on_map4(server, density);
}

// update the ressource on the map if the density is too low part 2
static void update_ressource_on_map2(server_t *server, density_t density)
{
    int x;
    int y;

    while (density.linemate < 0.3) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].linemate += 1;
        density = get_density(server);
    }
    while (density.deraumere < 0.15) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].deraumere += 1;
        density = get_density(server);
    }
    update_ressource_on_map3(server, density);
}

// update the ressource on the map if the density is too low
void update_ressource_on_map(server_t *server, int *cmpt_update)
{
    density_t density;
    int x;
    int y;

    if (server->start_game == false)
        return;
    if (*cmpt_update != 20)
        return;
    density = get_density(server);
    while (density.food < 0.5) {
        x = rand() % server->serverConfig->map_width;
        y = rand() % server->serverConfig->map_height;
        server->serverConfig->map->tiles[y][x].food += 1;
        density = get_density(server);
    }
    update_ressource_on_map2(server, density);
    *cmpt_update = 0;
}
