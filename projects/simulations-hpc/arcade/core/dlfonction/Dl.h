/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** dl
*/

#ifndef DL_H_
    #define DL_H_

#include <dlfcn.h>
#include <stdio.h>

void *dl_sym(void *handle, const char *name);
void *dl_open(const char *path);
void *dl_close(void *handle);
char *dl_error();

#endif /* !DL_H_ */
