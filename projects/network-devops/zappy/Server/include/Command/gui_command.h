/*
** EPITECH PROJECT, 2024
** New serveur
** File description:
** gui_command
*/

#ifndef GUI_COMMAND_H_
    #define GUI_COMMAND_H_

    #include "../Server/server.h"

typedef struct incantation_s {
    int x;
    int y;
    int level;
    int player_id;
    int nb_players;
    int players[MAX_CLIENTS];
    int result;
} incantation_t;

typedef struct player_inventory_s {
    int player_id;
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int player;
} player_inventory_t;

typedef struct player_s {
    int player_id;
    int x;
    int y;
    int orientation;
    int level;
    char *team_name;
} player_t;

typedef struct egg_s {
    int player_id;
    int egg_id;
    int x;
    int y;
} egg_t;

void cmd_bct(server_t *server);
void cmd_ebo(server_t *server, int egg_id);
void cmd_edi(server_t *server, int egg_id);
void cmd_enw(server_t *server, egg_t egg);
void cmd_msz(server_t *server);
void cmd_pbc(server_t *server, int player_id, char *message);
void cmd_pdi(server_t *server, int player_id);
void cmd_pdr(server_t *server, int player_id, int resource_id);
void cmd_pex(server_t *server, int player_id);
void cmd_pfk(server_t *server, int player_id);
void cmd_pgt(server_t *server, int player_id, int resource_id);
void cmd_pic(server_t *server, incantation_t *incantation);
void cmd_pie(server_t *server, incantation_t *incantation);
void cmd_pin(server_t *server, player_inventory_t *player_inventory);
void cmd_plv(server_t *server, int player_id, int level);
void cmd_pnw(server_t *server, player_t *new_player);
void cmd_ppo(server_t *server, player_t *player);
void cmd_sbp(server_t *server);
void cmd_seg(server_t *server, char *message);
void cmd_sgt(server_t *server);
void cmd_smg(server_t *server, char *message);
void cmd_sst(server_t *server);
void cmd_suc(server_t *server);
void cmd_tna(server_t *server);

void command_tna(server_t *server, char *buffer);
void command_suc(server_t *server, char *buffer);
void command_sst(server_t *server, char *buffer);
void command_sgt(server_t *server, char *buffer);
void command_ppo(server_t *server, char *buffer);
void command_plv(server_t *server, char *buffer);
void command_pin(server_t *server, char *buffer);
void command_msz(server_t *server, char *buffer);
void command_mct(server_t *server, char *buffer);
void command_bct(server_t *server, char *buffer, int client);

#endif /* !GUI_COMMAND_H_ */
