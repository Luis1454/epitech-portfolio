/*
** EPITECH PROJECT, 2021
** include.h
** File description:
** custom graphical include
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct screen
{
    int off;
    int Xsize;
    int Ysize;
    int shutter;
    sfColor *pixels;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;
    sfSprite *traceMap;
    sfSprite *pln_sprite;
    sfSprite *twr_sprite;
    sfTexture *trace;
    sfTexture *texture;
    sfTexture *pln_texture;
    sfTexture *twr_texture;
    sfText *text;
    sfFont *font;
    sfCircleShape *circle;
    sfRectangleShape *rect;
} Screen;

typedef struct stat
{
    int nbTowers;
    int nbPlanes;
    int i;
} Stat;

typedef struct plane_s
{
    sfSprite *sprite;
    char name[40];
    int id;
    double X;
    double Y;
    double Xa;
    double Ya;
    double Xb;
    double Yb;
    int take_of_delay;
    double Xspeed;
    double Yspeed;
    char plate[4];
} Plane;

typedef struct tower_s
{
    sfSprite *sprite;
    int id;
    char name[40];
    int X;
    int Y;
    int radius;
    char plate[4];
} Tower;

sfColor get_color(int v);

void init_A(Screen *s);

void init_B(Screen *s);

int is_in_circle(int len, int size, Plane p, Tower t[len]);

void plane_loop_A(Screen *s, Stat *st, Plane planes[], Tower towers[]);

void plane_loop_B(Screen *s, Stat *st, Plane planes[], Tower towers[]);

void tower_loop(Screen *s, Stat *st, Tower towers[]);

int get_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);

int get_warning(int nb, sfRectangleShape *rect, Plane plane, Plane p[nb]);

int parser(char *filename, Plane planes[], Tower towers[]);

int skip_spaces(char *line, int i);

int get_T_len(int len, Tower towers[len]);

int get_objects(char *line, int len, Plane planes[len], Tower towers[len]);

char *get_plate(char *plate);

int get_P_len(int len, Plane planes[len]);

int get_P_name(int len, Plane planes[len]);

int get_T_plate(int len, Tower towers[len]);

int get_collide(int len, int l, Plane plane, Plane p[len]);

int get_len_bf_dot(char *str);

int are_equals(char *str, char *test);

int get_warning(int nb, sfRectangleShape *rect, Plane plane, Plane p[nb]);

int my_radar(Stat *st, Plane planes[], Tower towers[]);

int get_T_text(sfRenderWindow *window, sfText *text, Tower tower);

int get_T_radius_label(sfRenderWindow *w, sfText *text, Tower tower, int off);

int get_T_circle(sfRenderWindow *w, sfCircleShape *circle,
    Tower tower, int off);

int test_null(FILE *fp);

#endif /* INCLUDE_H_ */
