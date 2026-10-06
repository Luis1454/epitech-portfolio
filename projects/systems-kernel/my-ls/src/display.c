/*
** EPITECH PROJECT, 2021
** display.c
** File description:
** display functions
*/

#include "../include/mylist.h"
#include "../include/my.h"
#include "../include/my_macro_abs.h"

int display_asc(read_list_t *head, int *tab, int nb, int *format)
{
    read_list_t *h = head;

    for (int i = 0; h != NULL; h = h->next) {
        if ((*h->data->d_name != '.' || tab['a'])
        && (h->data->d_type != DT_DIR || !format[1])) {
            str_contain(h->data->d_name, "# ") ?
            my_printf(!i ? "\'%s\'" : !format[0] || (i % nb) ? "  \'%s\'" :
            "\n\'%s\'", h->data->d_name) : my_printf(!i ? "%s" : !format[0]
            || (i % nb) ? "  %s" : "\n%s", h->data->d_name);
            i++;
        }
    }
    my_putchar('\n');
    return 0;
}

int format_rights(int nb)
{
    char *rights[] = {"---", "--x", "-W-", "-wx", "r--", "r-x", "rw-", "rwx"};

    for (int i = 2; i >= 0; i--)
        my_putstr(rights[nb % my_compute_power_it(10,
        i + 1) / my_compute_power_it(10, i)]);
    my_putstr(". ");
    return 0;
}

int format_date(char *str)
{
    int i = 0;
    int n = 0;

    for (; str[i] && str[i - 1] != ' '; i++);
    for (; str[i] && n <= 1; n += str[i + 1] == ':', i++)
        my_putchar(str[i]);
    my_putchar(' ');
    return 0;
}

int format_list(char *str, int state)
{
    struct stat buf;
    int res;

    if (stat(str, &buf) == -1)
        return 0;
    if (state) {
        my_printf("%c", buf.st_nlink > 1 ? 'd' : '-');
        format_rights(my_getbase(buf.st_mode, 8));
        my_printf("%i ", buf.st_nlink);
        my_printf("%s ", getpwuid(buf.st_uid)->pw_name);
        my_printf("%s ", getgrgid(buf.st_gid)->gr_name);
        my_printf("%i ", buf.st_size);
        format_date(ctime((const time_t *)&buf.st_mtim));
    }
    res = buf.st_blocks;
    return res;
}

int display_list(read_list_t *head, int *tab, char *path, int *format)
{
    read_list_t *h = head;
    int nb = 0;

    path = my_strlen(path) > 1 ? my_weak_strcat(path,
    path[my_strlen(path) - 1] == '/' ? "" : "/") : "./";
    for (int i = 0; h != NULL || head == NULL; h = h->next) {
        if ((*h->data->d_name != '.' || tab['a'])
        && (h->data->d_type != DT_DIR || !format[1])) {
            nb += format_list(my_weak_strcat(path,
            h->data->d_name), format[2]);
            format[2] ? my_printf(str_contain(h->data->d_name, "# ")
            ? "\'%s\'\n" : "%s\n", h->data->d_name) : 0;
            i++;
        }
    }
    return nb;
}
