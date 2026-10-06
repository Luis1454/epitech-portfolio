/*
** EPITECH PROJECT, 2021
** MYPRINT.h
** File description:
** file with the prototype from the libmy
*/

#include <stdarg.h>
#include <string.h>

#ifndef MYPRINT_H_
    #define MYPRINT_H_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void integers(va_list *list);
void character(va_list *list);
void strings(va_list *list);
int cmp(char a, char b, char *c);
void my_alpha(va_list *list);
int my_printf(char *s, ...);

#endif /* MYPRINT_H_ */
