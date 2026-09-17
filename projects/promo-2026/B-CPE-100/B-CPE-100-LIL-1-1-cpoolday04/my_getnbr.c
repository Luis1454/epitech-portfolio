/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** task05
*/

#include <stdio.h>

int check_num(int n)
{
	int state;
	if (n == "-" || n == " ")
	{
		/* code */
		printf("");
	}
	return state;
}

int my_getnbr(char const *str)
{
	int v = 0;
	const char *ptr1;
	ptr1 = str;
	while (*ptr1 != 0) {
	    ptr1++;
	    v++;
	}

	int i;
	for(i = 1; i < v; i++) {
		check_num(str[i]);
	}
}