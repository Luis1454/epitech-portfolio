/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** SBML project
*/

#include "../include/my.h"
#include "../include/sbml.h"
#include "../include/my_macro_abs.h"
#include "../include/mylist.h"

int display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tSBMLfile\tSBML file\n");
    my_putstr("\t-i ID\t\tid of the compartment, reaction or product to be ");
    my_putstr("extracted\n\t\t\t(ignored if uncorrect)\n");
    my_putstr("\t-e\t\tprint the equation if a reaction ID is given as ");
    my_putstr("argument\n\t\t\t(ignored otherwise)\n");
    my_putstr("\t-json\t\ttransform the file into a JSON file\n");
    return 0;
}

char *load_file(const char *path)
{
    int fd = open(path, O_RDONLY);
    char *str = NULL;
    struct stat st;

    if (fd == -1)
        return NULL;
    stat(path, &st);
    str = malloc(sizeof(char) * (st.st_size + 2));
    if (!str)
        return NULL;
    read(fd, str, st.st_size);
    str[st.st_size] = str[st.st_size - 1] == '\n' ? 0 : '\n';
    str[st.st_size + 1] = 0;
    return str;
}

int describe_balises(node_t *head)
{
    node_t *lst = NULL;

    sort_node(&head);
    for (node_t *tmp = head; tmp; tmp = tmp->next)
        if (get_nb_args(tmp->args) && !is_in_lst(lst, tmp->name))
            append_node(&lst, tmp->str);
    for (node_t *tmp = lst; tmp; tmp = tmp->next) {
        my_printf("%s\n", tmp->name);
        for (args_t *arg = tmp->args; arg; arg = arg->next)
            my_printf("--->%s\n", arg->var);
    }
    free_nodes(lst);
    return 0;
}

int sbml_core(char *str, int ac, char * const *av)
{
    node_t *head = get_balises_from_str(str);

    if (!head)
        return 84;
    if (ac == 2)
        return describe_balises(head);
    if (ac >= 4 && !my_strcmp(av[2], "-i"))
        return handle_i_flag(head, av[3], ac == 5 ? av[4] : 0);
    return 84;
}

int main(int ac, char * const *av)
{
    char *str = NULL;

    if (ac < 2 || ac > 5)
        return 84;
    if (!my_strcmp(av[1], "-h"))
        return display_help();
    str = load_file(av[1]);
    return sbml_core(str, ac, av);
}
