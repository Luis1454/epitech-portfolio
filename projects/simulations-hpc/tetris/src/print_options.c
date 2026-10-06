/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** print_options
*/

#include "../includes/tetris.h"

void print_special_ter(int key)
{
    switch (key) {
        default:
            my_putchar(key);
            break;
        case 260:
            my_putstr("KEY_DEL");
            break;
        case 261:
            my_putstr("KEY_HOME");
            break;
        case 259:
            my_putstr("KEY_END");
            break;
        case 258:
            my_putstr("KEY_INSERT");
            break;
    }
}

void print_special_bis(int key)
{
    switch (key) {
        default:
            print_special_ter(key);
            break;
        case 339:
            my_putstr("KEY_PGUP");
            break;
        case 340:
            my_putstr("KEY_PGDN");
            break;
        case 9:
            my_putstr("KEY_TAB");
            break;
        case 263:
            my_putstr("KEY_BACKSPACE");
            break;
        case 27:
            my_putstr("KEY_ESCAPE");
            break;
    }
}

void print_special(int key)
{
    switch (key) {
        default:
            print_special_bis(key);
            break;
        case 260:
            my_putstr("KEY_LEFT");
            break;
        case 261:
            my_putstr("KEY_RIGHT");
            break;
        case 259:
            my_putstr("KEY_UP");
            break;
        case 258:
            my_putstr("KEY_DOWN");
            break;
        case 10:
            my_putstr("KEY_ENTER");
            break;
    }
}

void print_key(char *str, int key)
{
    my_putstr(str);
    my_putstr(": ");
    if (key >= 265 && key <= 276) {
        my_putstr("KEY_F");
        my_put_nbr(key - 264);
    } else
        print_special(key);
    my_putstr(" (");
    my_put_nbr(key);
    my_putstr(")\n");
}

void print_options(Options *opt)
{
    print_key("Key left", opt->left);
    print_key("Key right", opt->right);
    print_key("Key turn", opt->turn);
    print_key("Key drop", opt->drop);
    print_key("Key quit", opt->quit);
    print_key("Key pause", opt->pause);
    my_putstr("Next: ");
    my_putstr((opt->hide) ? "No\n" : "Yes\n");
    my_putstr("Level: ");
    my_put_nbr(opt->level);
    my_putstr("\nSize: ");
    my_put_nbr(opt->map_size[0]);
    my_putchar('*');
    my_put_nbr(opt->map_size[1]);
    my_putstr("\n\n");
}
