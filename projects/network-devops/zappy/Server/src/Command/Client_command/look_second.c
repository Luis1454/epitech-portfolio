/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** look_second
*/

#include "../../../include/Command/client_command.h"
#include "../../../include/Utils/utils.h"

// add the content of a tile in a string
static void add(int p, char **str, char *msg)
{
    if (p != 0)
        for (int i = 0; i < p; i++) {
            *str = add_in_str(*str, " ");
            *str = add_in_str(*str, msg);
        }
}

// list of what the tile can contain
static void list_of_content(char **str, int x, int y, server_t *server)
{
    int p = 0;

    p = server->serverConfig->map->tiles[y][x].linemate;
    add(p, str, "linemate");
    p = server->serverConfig->map->tiles[y][x].deraumere;
    add(p, str, "deraumere");
    p = server->serverConfig->map->tiles[y][x].sibur;
    add(p, str, "sibur");
    p = server->serverConfig->map->tiles[y][x].mendiane;
    add(p, str, "mendiane");
    p = server->serverConfig->map->tiles[y][x].phiras;
    add(p, str, "phiras");
    p = server->serverConfig->map->tiles[y][x].thystame;
    add(p, str, "thystame");
    p = server->serverConfig->map->tiles[y][x].food;
    add(p, str, "food");
    p = server->serverConfig->map->tiles[y][x].player;
    add(p, str, "player");
    if (server->serverConfig->map->tiles[y][x].egg == true)
        *str = add_in_str(*str, "egg");
}

// get the content of a tile
char *get_tile_content(char *str, int x, int y, server_t *server)
{
    if (y < 0)
        y = server->serverConfig->map_height - 1;
    if (x < 0)
        x = server->serverConfig->map_width - 1;
    if (y >= server->serverConfig->map_height)
        y = 0;
    if (x >= server->serverConfig->map_width)
        x = 0;
    list_of_content(&str, x, y, server);
    return str;
}

// 3 = ouest, 4 = nord
static void look_direction_second(server_t *server, client_t *client,
    look_t *look, char **str)
{
    if (client->orientation == 3) {
        *str = get_tile_content(*str, look->x - look->l,
        look->y - look->l + look->t, server);
        if (look->t != look->to_look - 1)
            *str = add_in_str(*str, ",");
    }
    if (client->orientation == 4) {
        *str = get_tile_content(*str, look->x - look->l +
        look->t, look->y - look->l, server);
        *str = add_in_str(*str, ",");
    }
}

// 1 = est, 2 = sud
void look_direction(server_t *server, client_t *client, look_t *look,
    char **str)
{
    if (client->orientation == 1) {
        *str = get_tile_content(*str, look->x + look->l,
        look->y - look->l + look->t, server);
        if (look->t != look->to_look - 1)
            *str = add_in_str(*str, ",");
    }
    if (client->orientation == 2) {
        *str = get_tile_content(*str, look->x - look->l +
        look->t, look->y + look->l, server);
        if (look->t != look->to_look - 1)
            *str = add_in_str(*str, ",");
    }
    look_direction_second(server, client, look, str);
}

// look in all directions
void action_look(server_t *server, client_t *client, char **str, look_t *look)
{
    for (int l = 1; l <= client->level; l++) {
        look->l = l;
        for (int t = 0; t < look->to_look; t++) {
            look->t = t;
            look_direction(server, client, look, str);
        }
        look->to_look += 2;
    }
}
