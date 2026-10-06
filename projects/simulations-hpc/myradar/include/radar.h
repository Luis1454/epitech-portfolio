/*
** EPITECH PROJECT, 2022
** radar.h
** File description:
** radar includes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <time.h>

#pragma once

#define FRAMERATE 60
#define PATH_HIST_LEN 1000
#define MARGIN_FACTOR 0.5
#define TAXIING_TIME 60 * 15
#define FLIGHT_EXCENTRICITY 10

typedef struct vect_3d {
    double x;
    double y;
    double z;
} vect_3d;


typedef union time {
    char mem[15];
    double t;
} Time;

typedef struct flight {
    char *step;
    char *from;
    char *to;
    double heading;
    vect_3d departure;
    vect_3d arrival;
    Time departure_ts;
    Time arrival_ts;
    double travelled_dist;
} Flight;

typedef struct plane {
    int waiting;
    char *name;
    char *callsign;
    char *type;
    char *status;
    double speed;
    double weight;
    double climb_rate;
    double climb_speed;
    double cruise_speed;
    double cruise_alt;
    double approach_rate;
    double approach_speed;
    double fuel_capacity;
    double fuel_consumption;
    double fuel;
    double distance_to_target;
    double stall_speed;
    double max_speed;
    double payload;
    double max_alt;
    double max_weight;
    Flight *flight;
    vect_3d pos;
    vect_3d vect;
    vect_3d *path;
} Plane;

typedef struct tower {
    char *name;
    char *icao;
    char *status;
    double range;
    int capacity;
    int nb_runways;
    double wind_dir;
    long nb_taxiing;
    double wind_speed;
    double length_runways;
    sfVector2f cast;
    vect_3d pos;
} Tower, tower;

typedef struct limit {
    sfVector2f min;
    sfVector2f max;
} Limit;

typedef struct path {
    Plane *plane;
    double altitude;
    double speed;
    double heading;
    int n;
} Path;

typedef struct screen {
    sfText *text;
    double time_in_sec;
    Time timestamp;
    double timewarp;
    sfTime time;
    int last_click_event;
    double map_ratio;
    int paused;
    sfTexture *path_texture;
    sfSprite *path_sprite;
    Path *path_mask;
    sfColor *path_mask_index;
    Plane *plane;
    Tower *tower;
    int nb_plane;
    int nb_tower;
    double f;
    Limit limit;
    sfFont *font;
    sfClock *clock;
    sfRenderWindow *window;
    sfSprite *plane_sprite;
    sfSprite *tower_sprite;
    sfTexture *tower_texture;
    sfTexture *plane_texture;
    sfRectangleShape *plane_rect;
    sfTexture *texture;
    sfVideoMode mode;
    sfSprite *sprite;
    sfVector2i mouse;
    sfVector2i size;
    sfVector2u fixed;
    vect_3d collide_metric;
    vect_3d range_metric;
    sfEvent event;
} Screen;

int is_in_box(vect_3d a, vect_3d b, vect_3d metric, double map_ratio);

int check_plane_info(Screen *s, char **line, int i);

int check_plane_name(Screen *s, char **line, int i);

int callsign_isfree(Screen *s, char *callsign, int i);

int check_plane_callsign(Screen *s, char **line, int i);

int check_plane_flight(Screen *s, char **line, int i);

int check_tower_info(Screen *s, char **line, int i);

int check_tower_icao(Screen *s, char **line, int i);

tower *get_tower_from_icao(Screen *s, char *icao);

int check_tower_name(Screen *s, char **line, int i);

double get_pythagore_3d(vect_3d a, vect_3d b, vect_3d metric);

void update_limits(Screen *s, sfVector2f pos);

int check_tower_coord(Screen *s, char **line, int i);

int check_tower_range(Screen *s, char **line, int i);

int check_tower_capacity(Screen *s, char **line, int i);

int check_plane_speed(Screen *s, char **line, int i);

int check_plane_altitude(Screen *s, char **line, int i);

int check_plane_rate(Screen *s, char **line, int i);

int check_map(Screen *s, const char *path);

sfColor set_color_by_distance(Screen *s, int i);

void sub_display_planes_a(Screen *s, int i, double f);

void sub_display_planes_b(Screen *s, int i, double f);

void sub_display_planes_c(Screen *s, int i, double f);

void sub_display_planes_d(Screen *s, int i);

void sub_display_planes_e(Screen *s, int i);

void update_path(Screen *s, int n);

void display_pathmask(Screen *s);

void trace_path(Screen *s);

void sub_trace_path(Screen *s, int n);

int init_plane(Screen *s);

int init_tower(Screen *s);

sfColor get_hue(double n);

int display_towers(Screen *s);

int display_tower_range(Screen *s, Tower tower);

int display_planes(Screen *s);

int display_plane_state(Screen *s, Plane plane, sfVector2f pos);

void add_text(Screen *s, sfText *t, char *str, sfVector2f pos);

double get_rate_to_tower(Screen *s, int i);

int init_pathmask(Screen *s);

void init_path_history(Screen *s, int i);

void reset_path_mask(Screen *s);

int init_window(Screen *s, sfVideoMode mode);

int init_tower_texture(Screen *s);

int init_plane_texture(Screen *s);

int has_priority(Screen *s, int i);

int is_plane_at_start(Plane plane, vect_3d size);

int is_plane_at_dest(Plane plane, vect_3d size);

void get_plane_collide(Screen *s, int i);

int check_tower_format(Screen *s, char *str, int t);

int tower_name_isfree(Screen *s, char *name, int i);

int start_by(char *str, char *start);

int check_time_format(Screen *s, char *str);

int check_plane_format(Screen *s, char *str, int p);

char *open_file(const char *path, int size);

int sub_check_map_a(Screen *s, char **rdr);

int sub_check_map_b(Screen *s, char **rdr);

int tower_exists(Screen *s, char *icao);

int check_speed(const char *str);

double get_min_dist(Screen *s, int i);

sfColor mix_color(sfColor a, sfColor b, double ratio);

int is_in_range(Screen *s, Plane plane);

void display_grid(Screen *s);

int display_file(const char *path);

int no_man_sky(Screen *s);

int init_plane_metric(Screen *s, char *str);

int init_tower_metric(Screen *s, char *str);

int check_metric(char **arr, char *str, char *type);

int display_tower_state(Screen *s, int i, sfVector2f pos);

char *my_strdup_up(char const *src, int up);

int flight_handling(Screen *s, char **line);

int get_planes_in_sky(Screen *s);
