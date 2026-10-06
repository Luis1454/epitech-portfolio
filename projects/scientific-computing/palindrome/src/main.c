/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** palindrome main file
*/

#include "../include/my.h"
#include "../include/palindrome.h"
#include "../include/handling.h"

int check_session(core_t *core, int i, int tmp)
{
    core->i = i;
    core->out = tmp;
    if (tmp == get_rev_int(tmp, core->b) && ((core->p != -1 && core->p == tmp)
    || core->n != -1) && core->i >= core->imin)
        return 0;
    if (i >= core->imax)
        return -1;
    return check_session(core, i + 1, tmp + get_rev_int(tmp, core->b));
}

int n_option(core_t *core)
{
    if (check_session(core, 0, core->n) == -1)
        my_printf("no solution\n");
    else
        my_printf("%d leads to %d in %d iteration(s) in base %d\n",
        core->n, core->out, core->i, core->b);
    free(core);
    return 0;
}

int p_option(core_t *core)
{
    int i = 1;
    int found = 0;

    if (core->p != get_rev_int(core->p, core->b)) {
        my_print_error("invalid argument\n");
        return 84;
    }
    for (; i <= core->p; i++)
        if (!check_session(core, 0, i) && core->out == core->p) {
            my_printf("%d leads to %d in %d iteration(s) in base %d\n",
            i, core->out, core->i, core->b);
            found++;
        }
    if (!found && core->p != 0)
        my_printf("no solution\n");
    free(core);
    return 0;
}

int palindrome(int ac, char * const *av)
{
    core_t *core = init_core(ac, av);

    if (!core)
        return 84;
    if (check_values(core)) {
        my_print_error("invalid argument\n");
        free(core);
        return 84;
    }
    if (core->n != -1)
        return n_option(core);
    if (core->p != -1)
        return p_option(core);
    free(core);
    return 0;
}

int main(int ac, char * const *av)
{
    if (!my_strcmp(av[1], "-h") && ac == 2)
        return display_help();
    if (!(2 <= ac && ac <= 9) || !(ac % 2)) {
        my_print_error("invalid argument\n");
        return 84;
    }
    return palindrome(ac, av);
}
