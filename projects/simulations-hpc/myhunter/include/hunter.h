/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** structures include
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <time.h>

#pragma once

#define FRAMERATE 60

typedef struct plane {
    int model;
    sfVector2f pos;
    sfVector2f vect;
} Plane;

typedef struct scoreboard {
    int start_score;
    int score;
    int best;
    sfFont *font;
    sfText *score_text;
    sfText *best_text;
} Board;

typedef struct screen {
    Board board;
    sfVertexArray *line;
    int last_click_event;
    int paused;
    Plane *plane;
    int nb_plane;
    double f;
    sfClock *clock;
    sfRenderWindow *window;
    sfSprite *plane_sprite;
    sfSprite *target_sprite;
    sfTexture *target_texture;
    sfTexture *plane_sheet;
    sfTexture *texture;
    sfVideoMode mode;
    sfSprite *sprite;
    sfVector2i mouse;
    sfVector2u size;
    sfVector2u fixed;
    sfEvent event;
} Screen;

int is_in_box(sfVector2i mouse, sfVector2f pos, int width, int height);

void sub_plane_loop(Screen *s, int i);

void plane_loop(Screen *s);

void reset_plane(Screen *s, int i);

void init_plane(Screen *s, int nb);

void init_text(Screen *s);

void init_game(Screen *s);

void compute_score(Screen *s);

void compute_line(Screen *s);

void compute_target(Screen *s);

void save_score(Screen *s);
