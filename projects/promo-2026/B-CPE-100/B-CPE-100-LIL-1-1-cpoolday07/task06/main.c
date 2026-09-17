/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** task06
*/

void my_putstr(char const *str);

int main(int argc, char **argv)
{
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < argc; j++) {
            if (argv[j][0] == i)
                my_putstr(argv[j]);
        }
    }

    return 0;
}
