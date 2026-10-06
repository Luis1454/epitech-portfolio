/*
** EPITECH PROJECT, 2023
** open.c
** File description:
** file handling functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"
#include <stdio.h>
#include <sys/stat.h>

char *get_file_content(char *path)
{
    FILE *file = fopen(path, "r");
    char *content = NULL;
    struct stat st;

    stat(path, &st);
    if (!file)
        return NULL;
    content = malloc(sizeof(char) * st.st_size + 1);
    if (!content)
        return NULL;
    fread(content, st.st_size, 1, file);
    content[st.st_size] = '\0';
    fclose(file);
    return content;
}

char **get_split_from_file(char *path)
{
    char *file = get_file_content(path);
    char **split = NULL;

    if (!file)
        return NULL;
    split = my_str_to_array(file, "\n");
    free(file);
    return split;
}

void help_panel(screen_t *s)
{
    sfVector2f size = {800, 600};
    sfVector2f pos = {s->size.x / 2 - size.x / 2, s->size.y / 2 - size.y / 2};
    frame_t frame = {(sfVector2f){pos.x + size.x - 50,
    pos.y + size.y - 25}, (sfVector2f){40, 20}};
    display_rect(s, pos, size, sfWhite);
    for (int i = 0; s->help[i]; i++)
        display_text(s, s->help[i], (sfVector2f)
        {pos.x + 10, pos.y + 10 + i * 20}, sfBlack);
    display_text(s, "Close", frame.a, sfBlack);
    if (is_in_box(frame, (sfVector2f){s->mouse_pos.x, s->mouse_pos.y})
    && sfMouse_isButtonPressed(sfMouseLeft))
        get_button_by_name(s->toolbar, "Help")->child->child->state = 0;
}

void about_panel(screen_t *s)
{
    sfVector2f size = {600, 100};
    sfVector2f pos = {s->size.x / 2 -
    size.x / 2, s->size.y / 2 - size.y / 2};
    frame_t frame = {(sfVector2f){pos.x + size.x - 50,
    pos.y + size.y - 25}, (sfVector2f){40, 20}};

    display_rect(s, pos, size, sfWhite);
    display_text(s, "Credits :", (sfVector2f)
    {pos.x + 10, pos.y + 10}, sfBlack);
    display_text(s, "- Luis Fernandes <>",
    (sfVector2f){pos.x + 20, pos.y + 30}, sfBlack);
    display_text(s, "Close", frame.a, sfBlack);
    if (is_in_box(frame, (sfVector2f){s->mouse_pos.x, s->mouse_pos.y})
    && sfMouse_isButtonPressed(sfMouseLeft))
        get_button_by_name(s->toolbar, "About")->state = 0;
}
