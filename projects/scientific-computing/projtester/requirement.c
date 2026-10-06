/*
** EPITECH PROJECT, 2022
** requirement.c
** File description:
** my_ps_synthesis function
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void my_ps_synthesis(void)
{
    FILE *file = NULL;
    int pid = fork();

    if (pid == -1)
        exit(84);
    if (!pid) {
        file = popen("ps", "r");
        for (char c = fgetc(file); c != EOF; c = fgetc(file))
            write(1, &c, 1);
        pclose(file);
        exit(0);
    } else
        wait(0);
}
