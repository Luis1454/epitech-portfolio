/*
** EPITECH PROJECT, 2023
** simple_verif
** File description:
** simple_verif
*/

#include "lemin.h"

int isdigite(char c)
{
    return (c >= '0' && c <= '9');
}

int count_number_boucle(char *str, int *count, int i)
{
    while (isdigite(str[i])) {
            if (str[i + 1] == '\0')
                return i;
            i++;
        }
        *count = *count + 1;
    return i;
}

int count_number(char *str)
{
    int count = 1;
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        i = count_number_boucle(str, &count, i);
    }
    return count;
}

char **error(char **all_info, int i)
{
    if (i == 0)
        write(2, "ERROR: number of ants\n", 23);
    if (i == 1)
        write(2, "ERROR: rooms\n", 14);
    if (i == 2)
        write(2, "ERROR: error in start\n", 23);
    if (i == 3)
        write(2, "ERROR: error in end\n", 21);
    my_free_array(all_info);
    return (NULL);
}

char **clean_tab(char **all_info)
{
    if (all_info == NULL)
        return (NULL);
    for (int i = 0; all_info[i] != NULL; i++) {
        all_info[i] = clean_str(all_info[i]);
    }
    return (all_info);
}
