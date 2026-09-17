/*
** EPITECH PROJECT, 2022
** my_params_to_array.c
** File description:
** store all arguments to a struct
*/

#include "../../include/my.h"
#include "../../include/struct.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *out = malloc(sizeof(struct info_param) * ac);

    for (int i = 0; i < ac; i++) {
        out[i].length = my_strlen(av[i]);
        out[i].str = my_strdup(av[i]);
        out[i].copy = my_strdup(av[i]);
        out[i].word_array = my_str_to_word_array(av[i]);
    }
    return out;
}
