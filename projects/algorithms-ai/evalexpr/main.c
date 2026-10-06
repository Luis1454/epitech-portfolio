/*
** EPITECH PROJECT, 2021
** evalExpr
** File description:
** compute a mathematical expression
*/

#include "include/my.h"

int get_priority(char *str)
{
    int cnt = 0;
    int offset = 0;
    char out[my_strlen(str)];
    int i = 0;

    for (i; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            int nb_parent = 0;

            i++;
            cnt++;
            offset = i;
            while (str[i] != ')'){
                i++;
                if (!nb_parent)
                    out[i - offset] = str[i];
                if (str[i] == '(')
                    nb_parent++;
                if (str[i] == ')')
                    nb_parent--;
            }
            cnt++;
        } else {
            my_putstr("ok\n");
        }
    }
    my_putstr(out);
    my_putstr("\n");
}

int eval_expr(char const *str)
{
    int nb1;
    int val = 0;
    int res = 0;
    int v = 1;

    for (int i = 0; i < my_strlen(str); i++){
        if (res != 0 && v){
            nb1 = str[i-1]-48;
            v = 0;
        } else
            nb1 = val;

        val = 0;
        if (str[i] == '*'){
            val = mult(str[i-1]-48, str[i+1]-48);
        }
        if (str[i] == '/')
            val = div(str[i-1]-48, str[i+1]-48);
        if (str[i] == '%')
            val = mod(str[i-1]-48, str[i+1]-48);
        res += val;
    }

    for (int i = 0; i < my_strlen(str); i++){
        if (res != 0 && v){
            nb1 = str[i-1]-48;
            v = 0;
        } else
            nb1 = val;

        if (str[i] == '+')
            val = add(nb1, str[i+1]-48);
        else if (str[i] == '-')
            val = sub(nb1, str[i+1]-48);
        else
            val = 0;
        res += val;
    }
    return res;
}

int main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return 84;
}
