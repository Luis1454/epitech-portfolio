/*
** EPITECH PROJECT, 2024
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** server_struct
*/

#ifndef SERVER_STRUCT_H_
    #define SERVER_STRUCT_H_

    #define BUFFER_SIZE 1024
    #define MAX_CLIENTS 100
    #define MAX_REQUEST 10

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct tile_s {
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int food;
    bool egg;
    int player;
} tile_t;

typedef struct map_s {
    tile_t **tiles;
} map_t;

typedef struct egg_fork_s {
    int x;
    int y;
    int id;
    int time;
    int is_hatched;
    int is_fork;
} egg_fork_t;

typedef struct team_s {
    char *name;
    int client_nbr;
    int number_place_available;
    int fork;
    int x_fork;
    int y_fork;
    egg_fork_t *egg;
} team_t;

typedef struct serverConfig_s {
    char *ip;
    int port_nb;
    int map_width;
    int map_height;
    int teams_nb;
    int client_nb;
    int client_connected;
    int frequence;
    map_t *map;
    int max_clients_nbr;
    team_t *teams;
} serverConfig_t;

typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int player;
} inventory_t;

typedef struct client_s {
    int socket;
    bool is_connected;
    bool is_gui;
    char **request;
    int request_nbr;
    int id;
    char *team_name;
    inventory_t *inventory;
    int x;
    int y;
    int width;
    int heigt;
    int level;
    int orientation;
    int is_incanting;
    int is_dead;
    int is_graphical;
    int is_ejecting;
    int is_broadcasting;
    int is_forking;
    int is_taking;
    int is_setting;
    int is_inventory;
    int is_connect_nbr;
    int is_look;
    int is_right;
    int is_left;
    int is_forward;
    int is_incantation;
    int is_unknown;
    int is_broadcast;
    char *broadcast_cmd;
    int is_eject;
    int is_fork;
    int is_take_object;
    char *take_object_cmd;
    int is_set_object;
    char *set_object_cmd;
    int action;
    int request_action;
} client_t;

typedef struct server_s {
    serverConfig_t *serverConfig;
    int server_fd;
    struct sockaddr_in address;
    int addrlen;
    client_t *clients;
    int clients_nbr;
    fd_set readfds;
    int max_sd;
    int nbr_clients_connected;
    bool start_game;
    int update;
} server_t;

typedef struct density_s {
    float food;
    float linemate;
    float deraumere;
    float sibur;
    float mendiane;
    float phiras;
    float thystame;
} density_t;

#endif /* !SERVER_STRUCT_H_ */
