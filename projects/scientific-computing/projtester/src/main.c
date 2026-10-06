/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main file
*/

#include "../include/my.h"
#include "../include/tester.h"
#include "../include/handling.h"
#include <stdio.h>

char *get_path(char *path, char *middle, char *name, char *end)
{
    int len = my_strlen(path) + my_strlen(middle) + my_strlen(name) +
        my_strlen(end) + 1;
    char *res = malloc(sizeof(char) * len);

    if (!res)
        return NULL;
    res[0] = 0;
    my_strcat(res, path);
    my_strcat(res, middle);
    my_strcat(res, name);
    my_strcat(res, end);
    return res;
}

int get_folder_content(list_t **list, char *path, int depth)
{
    struct dirent *dirent = NULL;
    DIR *dir = opendir(path);
    list_t *tmp = NULL;
    int i = 0;

    if (!dir)
        return 84;
    for (dirent = readdir(dir); dirent; dirent = readdir(dir), i++) {
        if (dirent->d_name[0] == '.')
            continue;
        append_node(list, dirent->d_name);
        if (dirent->d_type == DT_DIR && *list) {
            tmp = get_node(*list, dirent->d_name);
            get_folder_content(&tmp->child, get_path(path, "/",
            dirent->d_name, ""), depth + 1);
        }
    }
    sort_tree(list);
    free(path);
    return (!!closedir(dir)) * 84;
}

int open_childs(char *path, int ac, char **av, char *bin_path)
{
    DIR *dir = opendir(path);
    list_t *list = NULL;
    struct dirent *dirent = NULL;

    if (!dir || (dirent = readdir(dir)) == NULL) {
        dir ? closedir(dir) : 0;
        return 1;
    }
    path[my_strlen(path) - 1] = path[my_strlen(path) - 1] == '/'
    ? 0 : path[my_strlen(path) - 1];
    ac == 2 ? printf("%s\n", get_last_element(path)) : 0;
    if (get_folder_content(&list, my_strdup(path), 1)) {
        closedir(dir);
        return 84;
    }
    closedir(dir);
    return run_tests(list, ac, av, bin_path);
}

int sub_main(int ac, char **av, char **env, int st)
{
    int state = 0;
    int success = 0;
    char *tmp = NULL;
    char *path = get_env_path(env);
    char **paths = my_str_to_array(path, ":", "");

    for (int i = 0; paths[i] && st; i++) {
        if ((state = open_childs(tmp = get_path(paths[i],
        "/", av[1], ""), ac, av, paths[i])) == 84) {
            free_array(paths);
            free(path);
            free(tmp);
            return 84;
        }
        free(tmp);
        success += !state;
    }
    free_array(paths);
    free(path);
    return !success && st ? 84 : 0;
}

int main(int ac, char **av, char **env)
{
    int st = 0;

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return display_help();
    if (ac > 4 || ac < 2 || failed_open(av[1]))
        return 84;
    if (ac >= 2 && (st = open_childs(av[1], ac, av, "./")) == 84)
        return 84;
    return sub_main(ac, av, env, st);
}
