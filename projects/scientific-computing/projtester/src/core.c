/*
** EPITECH PROJECT, 2023
** core.c
** File description:
** core of the program
*/

#include "../include/my.h"
#include "../include/tester.h"

int search_tests(list_t *list, char *name, char *bin_path)
{
    char *tmp = malloc(sizeof(char) *
    (my_strlen(bin_path) + my_strlen(name) + 2));

    tmp = my_memset(tmp, 0, my_strlen(bin_path) + my_strlen(name) + 2);
    tmp = my_strcpy(tmp, bin_path);
    tmp = my_strcat(tmp, "/");
    tmp = my_strcat(tmp, name);

    if (access(tmp, F_OK) == -1
    || access(tmp, X_OK) == -1) {
        free_tree(list);
        free(tmp);
        return 1;
    }
    free_tree(list);
    free(tmp);
    return 0;
}

int display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./projTester TRD [BFT] [outputFile]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tTRD\t\troot directory of all the tests\n");
    my_putstr("\tBFT\t\tbinary file to be tested\n");
    my_putstr("\toutputFile\tfile in which the result is printed\n");
    return 0;
}

int run_tests(list_t *list, int ac, char **av, char *bin_path)
{
    if (ac == 2) {
        display_tree(list, 1);
        free_tree(list);
        return 0;
    }
    if (ac > 2)
        return search_tests(list, av[2], bin_path);
    free_tree(list);
    return 84;
}

int is_folder_valid(char *path)
{
    DIR *dir = opendir(path);

    if (!dir) {
        closedir(dir);
        return 0;
    }
    closedir(dir);
    return 1;
}
