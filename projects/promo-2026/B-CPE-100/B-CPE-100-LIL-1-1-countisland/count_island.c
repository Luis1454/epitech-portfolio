#include <stdlib.h>

char *my_strdup(char const *src);

int is_digit(int i)
{
    int s;
    s = (47 < i && i < 58);

    return s;
}

int count_island(char** world){
    int i;
    int nb = 0;

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 66; j++) {
            if (world[i][j] != '.') {
                if (is_digit(world[i][j-1]))
                    world[i][j] = world[i][j-1];
                if (is_digit(world[i-1][j]))
                    world[i][j] = world[i-1][j];
                if (!(is_digit(world[i-1][j]) || is_digit(world[i][j-1]))) {
                    world[i][j] = nb+48;
                    nb++;
                }
            }
        }
    }

    return nb;
}
