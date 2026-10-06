/*
** EPITECH PROJECT, 2022
** assert_a.c
** File description:
** assertion functions
*/

#include "../include/my.h"
#include "../include/paint.h"
#include "../include/handling.h"
#include "../include/my_macro_abs.h"

int check_extension(char *str, char *ext)
{
    int len = my_strlen(str);
    int ext_len = my_strlen(ext);

    if (len < ext_len)
        return 0;
    return !my_strcmp(&str[len - ext_len], ext);
}

void sub_validation(screen_t *s, struct dirent *file)
{
    if (file->d_type != 4 && (check_extension(file->d_name, ".png")
    || check_extension(file->d_name, ".jpg")
    || check_extension(file->d_name, ".jpeg")
    || check_extension(file->d_name, ".bmp"))) {
        if (s->file)
            free(s->file);
        s->file = malloc(sizeof(char) * 2048);
        s->file = my_strcpy(s->file, s->path);
        s->file = my_strcat(s->file, "/");
        s->file = my_strcat(s->file, file->d_name);
        get_button_by_name(s->toolbar, "Open")->state = 0;
        if (s->image)
            destroy_image(s->image);
        load_image(s);
        sfRenderWindow_setTitle(s->window, s->file);
    }
}

double check_validation(screen_t *s, struct dirent *file)
{
    int len = my_strlen(file->d_name) + 2;

    if (sfMouse_isButtonPressed(sfMouseLeft)
    && s->event.type == sfEvtMouseButtonReleased) {
        if (file->d_type == 4) {
            len += my_strlen(s->path);
            s->path = my_strcat(s->path, "/");
            s->path = my_strcat(s->path, file->d_name);
            resolve_path(s);
        }
        sub_validation(s, file);
    }
    return 0.35;
}
