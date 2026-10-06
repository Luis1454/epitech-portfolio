/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** init_map
*/

#include "../../../include/Server/server_struct.h"
#include "../../../include/Server/init.h"

// init the malloc for the map struct
static int init_struct_map(serverConfig_t *serverConfig, int y)
{
    serverConfig->map = malloc(sizeof(map_t));
    if (serverConfig->map == NULL) {
        perror("Failed to allocate memory for map");
        return 84;
    }
    serverConfig->map->tiles = malloc(sizeof(tile_t *) * y);
    if (serverConfig->map->tiles == NULL) {
        perror("Failed to allocate memory for tiles array");
        free(serverConfig->map);
        return 84;
    }
    return 0;
}

// init the content of the tile
static void init_tile(serverConfig_t *serverConfig, int i, int j)
{
    tile_t *tile = &serverConfig->map->tiles[i][j];

    tile->linemate = 0;
    tile->deraumere = 0;
    tile->sibur = 0;
    tile->mendiane = 0;
    tile->phiras = 0;
    tile->thystame = 0;
    tile->food = 0;
    tile->egg = false;
    tile->player = 0;
}

//quantities[0] = food,
//quantities[1] = linemate,
//quantities[2] = deraumere,
//quantities[3] = sibur,
//quantities[4] = mendiane,
//quantities[5] = phiras,
//quantities[6] = thystame
// calculate the number resource on the map
void resource_number(int map_width, int map_height, int *quantities)
{
    quantities[0] = map_width * map_height * FOOD_D;
    quantities[1] = map_width * map_height * LINEMATE_D;
    quantities[2] = map_width * map_height * DERAUMERE_D;
    quantities[3] = map_width * map_height * SIBUR_D;
    quantities[4] = map_width * map_height * MENDIANE_D;
    quantities[5] = map_width * map_height * PHIRAS_D;
    quantities[6] = map_width * map_height * THYSTAME_D;
}

// Function to place resources on the map tiles
void place(serverConfig_t *serverConf, int resource, int y, int x)
{
    switch (resource) {
        case 2:
            serverConf->map->tiles[y][x].deraumere++;
            break;
        case 3:
            serverConf->map->tiles[y][x].sibur++;
            break;
        case 4:
            serverConf->map->tiles[y][x].mendiane++;
            break;
        case 5:
            serverConf->map->tiles[y][x].phiras++;
            break;
        case 6:
            serverConf->map->tiles[y][x].thystame++;
            break;
        default:
            break;
    }
}

// Function to place resources on the map tiles
static void place_on_tile(serverConfig_t *serverConf, int *positions,
    int quantity, int resource)
{
    int pos;
    int x = 0;
    int y = 0;

    for (int i = 0; i < quantity; i++) {
        pos = positions[i];
        x = pos % serverConf->map_width;
        y = pos / serverConf->map_width;
        switch (resource) {
            case 0:
                serverConf->map->tiles[y][x].food++;
                break;
            case 1:
                serverConf->map->tiles[y][x].linemate++;
                break;
            default:
                place(serverConf, resource, y, x);
                break;
        }
    }
}

// Function to randomly place resources on the map
void place_resources(serverConfig_t *serverConfig,
    int resource, int quantity)
{
    int tiles_nb = serverConfig->map_width * serverConfig->map_height;
    int *positions = malloc(tiles_nb * sizeof(int));
    int j = 0;
    int tmp = 0;

    if (!positions) {
        perror("Failed to allocate memory for positions");
        return;
    }
    for (int i = 0; i < tiles_nb; i++)
        positions[i] = i;
    for (int i = 0; i < tiles_nb; i++) {
        j = rand() % tiles_nb;
        tmp = positions[i];
        positions[i] = positions[j];
        positions[j] = tmp;
    }
    place_on_tile(serverConfig, positions, quantity, resource);
    free(positions);
}

// Function to place resources on the map
void place_ressource(server_t *server)
{
    int quantity[7];

    resource_number(server->serverConfig->map_width,
    server->serverConfig->map_height, quantity);
    for (int i = 0; i < 7; i++)
        place_resources(server->serverConfig, i, quantity[i]);
}

// init the map
void init_map(server_t *server)
{
    if (init_struct_map(server->serverConfig,
    server->serverConfig->map_height) == 84)
        return;
    for (int i = 0; i < server->serverConfig->map_height; i++) {
        server->serverConfig->map->tiles[i] = malloc(sizeof(tile_t) *
        server->serverConfig->map_width);
        if (server->serverConfig->map->tiles[i] == NULL) {
            perror("Failed to allocate memory for tiles row");
            free(server->serverConfig->map->tiles);
            free(server->serverConfig->map);
            return;
        }
        for (int j = 0; j < server->serverConfig->map_width; j++)
            init_tile(server->serverConfig, i, j);
    }
    place_ressource(server);
}
