/*
** EPITECH PROJECT, 2021
** my_world.h
** File description:
** custom graphical includes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct font_s {
    sfFont *font;
    sfText *text;
    sfText *box;
    sfText *box_bis;
    char **menu_text;
    int menu_tex;
    char **brush_text;
    int brush_tex;
    char **winsize_text;
    int win_tex;
    int a_x;
    int a_y;
} Font_t;

typedef struct screen
{
    int Xsize;
    int Ysize;
    int shutter;
    Font_t *font;
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfVector2i mouse_pos;
} Screen;

typedef struct unit
{
    sfVector3f vect;
    sfColor *color;
    sfVector2f flat;
    sfTexture *texture;
} Unit;

typedef struct matrix_3d
{
    float x;
    float y;
    float z;
    float w;
} m3d;

typedef struct camera
{
    double X;
    double Y;
    double Z;
    double rot_X;
    double rot_Y;
    double rot_Z;
    double FOV;
    double zoom;
    m3d transform[4][4];
} Camera;

typedef struct brush
{
    double dist;
    int brush_size;
    int brush_state;
    sfVector2i select;
    sfVector2i nearest;
    sfColor brush_color;
    int nb_brush_points;
    double total_z_values;
    double brush_strength;
} Brush;

typedef struct map
{
    sfVector3f abs_rot;
    sfVector3f X_pos;
    sfVector3f Y_pos;
    sfVector3f Z_pos;
    Brush *b;
    double Xsize;
    double Ysize;
    double level;
    double cluster[1000];
    sfVertex v;
    sfVector2f **cast_map;
    sfVector3f **test;
    Camera *camera;
    Unit **matrix;
    m3d transform[4][4];
    sfColor *base_color;
    sfVertexArray *matrix_arr;
    sfClock *clock;
    sfTime time;
    int last_time;
    double rot;
    int i;
    int j;
} Map;

typedef struct menu
{
    sfSprite *background;
    sfTexture *t_backg;
} Menu;

int check_border(Map *map, sfVector2f vect);

void sub_switch_get_brush_points(Screen *s, Map *map,
sfVector2f b, sfVector2i v);

void sub_get_cluster_point(Screen *s, Map *map,
sfVector2i pos, double strength);

void build_axis(Screen *s, Map *map);

void sub_init_map(Map *map, int i);

void sub_ini_font(Screen *s);

void sub_init_font(Screen *s);

void sub_get_cluster_points(Screen *s, Map *map,
sfVector2i pos, double strength);

void get_cluster_points(Screen *s, Map *map,
sfVector2i pos, double strength);

void set_point_color(Screen *s, Map *map);

void name_init_font(char **brushmenu);

void sub_set_point_color(Screen *s, Map *map,
sfVector2f p, int size);

void reset_axis(Map *map, sfVector3f *vect);

double get_pythagore(sfVector2f A, sfVector2f B);

int is_min_lst(double *lst, int len, double nb);

void init_screen(Screen *s);

void init_map(Map *map);

int my_world(void);

int is_in_circle(int size, sfVector2f A, sfVector2f B);

int coord(Screen *s, Map *map);

void reset_evelation(Screen *s, Map *map);

void get_perlin_noise(Screen *s, Map *map, int size);

sfVector2f get_iso(Screen *s, Map *map, sfVector3f *vect, int state);

void get_2d_map(Screen *s, Map *map);

int draw_map(Screen *s, Map *map);

void init_font(Screen *s);

void destroy_font(Screen *s);

void get_perlin_noise(Screen *s, Map *map, int size);

void get_brush_color(Screen *s, Map *map);

int text(Screen *s);

void get_brush_points(Screen *s, Map *map);

void sub_get_brush_points(Screen *s, Map *map, double brush, int i);

void get_brush_size(Screen *s, Map *map);

void get_brush(Screen *s, Map *map);

void get_cursor_actions(Screen *s, Map *map, double strength);

void get_nearest_point(Screen *s, Map *map, sfVector2f pos);

int coord(Screen *s, Map *map);

void switch_get_brush_points(Screen *s, Map *map,
sfVector2f b, sfVector2i v);

void sub_set_point_color(Screen *s, Map *map, sfVector2f p, int size);

void button(Screen *s, sfEvent event);

void reset_evelation(Screen *s, Map *map);

void get_2d_map(Screen *s, Map *map);

void create_line(Map *map, sfVector2f p1, sfVector2f p2, sfVector3f vect3d);

void vertex_x(Screen *s, Map *map, int i, int j);

void vertex_y(Screen *s, Map *map, int i, int j);

#endif /* INCLUDE_H_ */
