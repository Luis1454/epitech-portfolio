/*
** EPITECH PROJECT, 2023
** my_rpg.h
** File description:
** my_rpg includes
*/


#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #define MAX_ZOOM 10.0
    #define MIN_ZOOM 0.1

    #include <stdio.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <dirent.h>
    #include <time.h>
    #include "mylist.h"

    typedef struct item {
        char *name;
        int id;
        int type;
        int value;
        int rarity;
        int level;
        int attack;
        int defense;
        int speed;
        int mana;
        int durability;
    } item_t;

    typedef struct player {
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
        sfVector2f scale;
        int **inventory;
        int life;
        int mana;
        int attack;
        int defense;
        int speed;
        int level;
        int xp;
        int money;
        int id;
        int max_life;
        int max_mana;
        int reverse;
        int is_inventory;
        int last_i_state;
        int walk_loop;
        int sprite_offset;
    } player_t;

    typedef struct map {
        sfVector2i size;
        sfSprite *sprite;
        int ***data;
        double f;
        double rescale;
        sfVector2i origin;
        double zoom_speed;
    } map_t;

    typedef struct button {
        char *label;
        int state;
        sfIntRect rect;
        struct button *next;
    } button_t;

    typedef struct menu {
        char *label;
        button_t *buttons;
        struct menu *next;
    } menu_t;

    typedef struct texture {
        sfTexture *iso;
        sfTexture **t;
        sfTexture *players;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f scale;
        sfTexture *items;
    } texture_t;

    typedef struct sound {
        float music_vol;
        float sound_vol;
        sfMusic *music;
        sfSound *click;
        sfSoundBuffer *click_buffer;
    } sound_t;

    typedef struct ennemy {
        sfSprite *sprite;
        sfVector2f pos;
        int life;
        int attack;
        int defense;
    } ennemy_t;

    typedef struct list {
        sfVector2i pos;
        struct list *next;
    } list_t;

    typedef struct game {
        int tex_id;
        int resolution;
        double scale;
        menu_t *menu;
        map_t *map;
        sfVector2i size;
        player_t *player;
        sfVector2i mouse_pos;
        sfRenderWindow *window;
        texture_t *texture;
        sfEvent event;
        sfClock *clock;
        sfRectangleShape *rect;
        sfText *text;
        sfFont *font;
        int menu_id;
        sound_t *sounds;
        item_t *items;
        int is_started;
        sfSprite *item_sprite;
        ennemy_t *ennemy1;
        ennemy_t *ennemy2;
        ennemy_t *ennemy3;
        int *ennemys_dead;
        DIR *dir;
        char *file;
        char *path;
        int last;
        double fade;
        double fade_speed;
    } game_t;

    /*init function */
    int init_game(void);

    int init_menu(game_t *game);

    int init_texture(game_t *game);

    void init_data(map_t *map, char **raw);

    sound_t *init_sounds(sound_t *sounds);

    int init_player(game_t *game);

    void init_items(game_t *game);

    void init_name_items_line_one(game_t *game, int *datas);


    /*check_error_handling function */
    int check_handling(char *str);

    void button_handling(game_t *game, char *name, char *menu);

    void init_text(game_t *game);

    void init_inventory(player_t *player);

    /*display function */
    int display_open(game_t *game);

    void display_vslider(game_t *game, sfFloatRect rect,
    sfColor color, double factor);

    int display_game(game_t *game);

    int display_menu(game_t *game);

    void display_button(game_t *game, button_t *button);

    void display_map_from_data(game_t *game, map_t *map);

    void display_slider(game_t *game, sfFloatRect rect, sfColor color,
    double factor);

    void display_inventory(game_t *game);

    void display_item(game_t *game, sfVector2f pos, int id);

    void display_details(game_t *game, sfVector2f pos, int id);

    void display_game_menu(game_t *game);

    void display_player(game_t *game);

    void get_angle(game_t *game);

    int display_about(game_t *game);

    int display_game(game_t *game);


    int display_settings(game_t *game);

    /*event function */
    void loop_wimdow(game_t *game);

    /*menu function */
    void append_menu(menu_t **head, char *label);

    void change_volume(game_t *game);

    /*lib function */
    char *my_strdup_up(char const *src, int up);

    void skip_all_delim(char const *str, int *i, char *limit);

    /*general function */
    sfVector2i id_to_iso(int id, sfVector2i size, sfVector2i offset,
    double rescale);

    void zoom_map(map_t *map);

    char *get_raw(char *path);

    int load_map(char *path, map_t *map);

    int contain_int(int c, int *str, int size);

    int is_in_rect(sfIntRect rect, sfVector2i mouse);

    menu_t *get_menu_by_name(menu_t *head, char *name);

    void append_button(button_t **head, char *label, int state, sfIntRect
    rect);

    button_t *get_buttons_by_name(button_t *head, char *name);

    int *set_int_tab(int *tab, int *args, int size);

    menu_t *get_menu_by_id(menu_t *head, int id);

    int get_id_by_menu_name(menu_t *head, char *name);

    item_t get_item_by_id(game_t *game, int id);

    void add_text(game_t *game, sfText *t, char *str, sfVector2f pos);


    void add_rect(game_t *game, sfVector2f pos, sfVector2f size, sfColor
    color);

    void display_block_from_id(game_t *game, int id, sfVector2i pos, double
    scale);

    void get_move(game_t *game);

    void display_value(game_t *game, sfVector2i pos, char *name, sfVector2f v);

    int get_pos_alt(game_t *game, sfVector2i pos);

    void add_text_at(game_t *game, sfText *t, char *str, sfVector2f pos);

    int get_pos_alt(game_t *game, sfVector2i pos);

    void check_hover(game_t *game, sfVector2f pos);

    void setup_item(item_t *item, int id, char *name, int *datas);

    sfColor get_color_by_name(char *name);
    void display_folder(game_t *game, char *path, sfVector2f pos);
    void resolve_path(game_t *g);
    double check_validation(game_t *g, struct dirent *file);
    void append_node(linked_list_t **head, void *data);
    void free_array(char **array);
    linked_list_t *create_node(void *data);
    struct dirent *get_file_from_pos(game_t *g, linked_list_t *l,
    sfVector2f pos);
    void set_resolution(game_t *game);
    void handle_animation(game_t *g);
    void add_ennemys(game_t *game, ennemy_t *ennemy, sfVector2f pos);
    void radar_ennemys(game_t *game);
#endif /* MY_RPG_H_ */
