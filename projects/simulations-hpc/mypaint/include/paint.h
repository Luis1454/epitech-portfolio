/*
** EPITECH PROJECT, 2022
** paint.h
** File description:
** paint includes
*/

#include "mylist.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <dirent.h>
#include <math.h>
#include <time.h>

#pragma once

#define MAX_INTERPOLATION 50
#define FRAMERATE 1000
#define HIST_LEN 1000
#define MARGIN_FACTOR 0.5
#define GRID_SIZE 20

typedef struct frame {
    sfVector2f a;
    sfVector2f b;
} frame_t;

typedef struct list {
    sfVector2i pos;
    struct list *next;
} list_t;

typedef struct shape {
    sfVector2f pos;
    sfColor color;
    char *name;
    int state;
    int size;
    int id;
} shape_t;

typedef struct slider {
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    double value;
    double min;
    double max;
    char *name;
    int state;
    int id;
} slider_t;

typedef struct brush {
    shape_t *shape;
    slider_t *opacity;
    slider_t *smooth;
    sfColor bg_color;
    slider_t *size;
    sfVector2i pos;
    sfColor color;
    char *name;
    struct brush *next;
} brush_t;

typedef struct button {
    sfColor color;
    sfColor hover;
    frame_t box;
    char *name;
    int id;
    int state;
    int visible;
    struct button *next;
    struct button *child;
} button_t;

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
    sfImage *img;
    sfVector2i pos;
    sfVector2u size;
    sfColor *pixels;
    int id;
    int state;
} image_t;

typedef struct screen {
    sfRenderWindow *window;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    image_t *image;
    sfView *view;
    DIR *dir;
    button_t *toolbar;
    frame_t draw_area;
    brush_t *brush;
    brush_t *current_brush;
    brush_t *eraser;
    sfEvent event;
    list_t *last_clicks;
    char *path;
    char *file;
    int state;
    int interpolation;
    int last_state;
    char **help;
    int is_help;
    int is_about;
    int is_new;
    int is_open;
    int is_save;
    int is_close;
    sfVector2i mouse_pos;
    sfVector2i size;
    sfVector2f map_pos;
    sfVector2f map_size;
    sfVector2f picker_pos;
    sfVector2f picker_size;
    sfFont *font;
    sfText *text;
} screen_t;

sfColor set_color_by_distance(double distance, double max_distance);

double get_pythagore(sfVector2f a, sfVector2f b);

int is_in_box(frame_t box, sfVector2f point);

int is_in_circle(sfVector2f center, sfVector2f point, double radius);

void add_brush(screen_t *s, int size, sfColor color, double smooth);

sfColor mix_color(sfColor a, sfColor b, double ratio);

void display_rect(screen_t *s, sfVector2f pos, sfVector2f size, sfColor color);

void display_color_ramp(screen_t *s,
sfVector2f pos, sfVector2f size, double lightness);

sfColor get_color_from_map(sfVector2f pos, sfVector2f size, sfVector2f mouse);

button_t *get_button_by_name(button_t *b, char *name);

int load_image(screen_t *s);

int destroy_image(image_t *image);

int create_new(screen_t *s, sfVector2i size, char *path);

int save_image(screen_t *s);

void display_slider(screen_t *s, slider_t *slider, int is_float);

slider_t *create_slider(sfVector2f pos, sfVector2f size,
sfVector2f limits, char *name);

void get_empty_pattern(screen_t *s, int margin, sfVector2f pos,
sfVector2f size);

void display_text(screen_t *s, char *str, sfVector2f pos, sfColor color);

void display_toolbar(screen_t *s);

void display_grid(screen_t *s, sfColor color, int margin);

void display_brush_circle(screen_t *s);

void display_color_map(screen_t *s, sfVector2f pos, sfVector2f size);

void panel_handler(screen_t *s);

void slider_handler(screen_t *s);

brush_t *get_brush_by_id(screen_t *s, int id);

void init_toolbar(screen_t *s);

void display_brush(screen_t *s, brush_t *brush);

void display_color_picker(screen_t *s);

struct dirent *get_file_from_pos(screen_t *s, linked_list_t *l, sfVector2f pos);

void init_circle(screen_t *s, int size, sfColor color);

void help_panel(screen_t *s);

char **get_split_from_file(char *path);

void about_panel(screen_t *s);

sfColor get_hue(double n);

void display_child(screen_t *s, button_t *b, int active);

void sub_slider(screen_t *s, slider_t *slider, int is_float, char *str);

void display_button(screen_t *s, button_t *b, int active);

int len_list(list_t *list);

int add_node(list_t **list, sfVector2i pos);

int remove_last_node(list_t **list);

double get_value_from_pos(slider_t *slider, sfVector2i pos);

void init_eraser(screen_t *s);

int get_nb_child(button_t *b);

void display_folder(screen_t *s, char *path, sfVector2f pos);

void append_button(button_t *b, char *name, frame_t frame);

void append_button_child(button_t *b, char *name, frame_t frame);

button_t *create_button(char *name,
frame_t frame, sfColor color, sfColor hover);

void append_node(linked_list_t **head, void *data);

linked_list_t *create_node(void *data);

void display_open_panel(screen_t *s, sfVector2f pos);

void display_save_panel(screen_t *s, button_t *b, int exists);

char *sub_resolve(char **path, int i);

void compute_draw_area(screen_t *s);

void resolve_path(screen_t *s);

void interpolate_brush(screen_t *s, sfVector2f pos);

void sub_edit_pixel(screen_t *s, sfVector2i a, sfVector2i b, sfColor color);

void edit_pixel(screen_t *s, sfColor color, int size, frame_t box);

void update_last_clicks(screen_t *s);

int main_loop(screen_t *s);

int cmp_dirent(struct dirent *a, struct dirent *b);

double check_validation(screen_t *s, struct dirent *file);

int is_in_slider(screen_t *s, slider_t *slider);

void set_slider_value(slider_t *slider, double value);
