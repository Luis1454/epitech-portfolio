/*
** EPITECH PROJECT, 2021
** my_print_comb2.c
** File description:
**
*/

#include <unistd.h>

int check_commas(int d, int s, int i, int j) {
   if (!(d >= 9 && s >= 8 && i >= 9 && j >= 9)) {
      write(1, ", ", 2);
   }
   return 0;
}

int content_3(int floor, int m, int c, int i, int j) {
    int a;
    int b;
    a = floor+i;
    b = floor+j;
    write(1, &m, 1);
    write(1, &c, 1);
    write(1, " ", 1);
    write(1, &a, 1);
    write(1, &b, 1);
    return 0;
}

int layer_3(int floor, int m, int c, int i, int j, int s, int d) {
    for(j=s+1;j<=9;j++){
        content_3(floor, m, c, i, j);
        check_commas(d, s, i, j);
    }
    return 0;
}

int my_print_comb2(void) {
    int i;
    int j;
    int d;
    int s;
    int c;
    int m;
    int floor;
    floor = 48;
    for (d=0;d<=9;d++) {
        m = floor+d;
        for (s=0;s<=9;s++) {
            c = floor+s;
            for (i=d;i<=9;i++) {
               layer_3(floor, m, c, i, j, s, d);
            }
        }
    }
    write(1, "\n", 1);
}
