/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Options management
*/

#include "../includes/tetris.h"

Options *init_options(void)
{
    Options *opt = malloc(sizeof(Options));

    opt->level = 1;
    opt->left = KEY_LEFT;
    opt->right = KEY_RIGHT;
    opt->turn = KEY_UP;
    opt->drop = KEY_DOWN;
    opt->quit = KEY_Q;
    opt->pause = KEY_SPACE;
    opt->map_size[0] = 20;
    opt->map_size[1] = 10;
    opt->hide = false;

    opt->debug = false;

    return opt;
}

void get_options(int ac, char **av, Options *opt)
{
    static struct option long_options[] = {
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"map-size", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {NULL, 0, NULL, 0}
    };
    int i = 0;
    char ch = getopt_long(ac, av, SHORTOPT, long_options, NULL);

    while (ch != -1) {
        choose_params(opt, ch, &i);
        ch = getopt_long(ac, av, SHORTOPT, long_options, NULL);
    }
}

void sub_choose_params(Options *opt, char ch)
{
    switch (ch) {
        case 'd':
            opt->drop = my_atoi(optarg);
            break;
        case 'q':
            opt->quit = my_atoi(optarg);
            break;
        case 'p':
            opt->pause = my_atoi(optarg);
            break;
        case 'w':
            opt->hide = true;
            break;
        case 'D':
            opt->debug = true;
            break;
        default:
            break;
    }
}

void choose_params(Options *opt, char ch, int *i)
{
    switch (ch) {
        case 'L':
            opt->level = my_atoi(optarg);
            break;
        case 'l':
            opt->left = my_atoi(optarg);
            break;
        case 'r':
            opt->right = my_atoi(optarg);
            break;
        case 't':
            opt->turn = my_atoi(optarg);
            break;
        case 'm':
            opt->map_size[(*i)++] = my_atoi(optarg);
            break;
        default:
            sub_choose_params(opt, ch);
            break;
    }
}
